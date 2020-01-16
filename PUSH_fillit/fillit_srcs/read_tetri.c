/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jworden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:06:48 by jworden           #+#    #+#             */
/*   Updated: 2019/10/08 18:12:19 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"
#include "libft.h"
#include <stdlib.h>

/*
** direction: 0 is left, 1 is up
*/

static void	push(t_tetri *tetri, int direction)
{
	int	i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 4)
		{
			if (direction)
				tetri->body[i * 4 + j] = tetri->body[(i + 1) * 4 + j];
			else
				tetri->body[j * 4 + i] = tetri->body[j * 4 + i + 1];
			j++;
		}
		i++;
	}
	j = -1;
	while (++j < 4)
	{
		if (direction)
			tetri->body[12 + j] = '.';
		else
			tetri->body[j * 4 + 3] = '.';
	}
}

static void	align_tetri(t_tetri *tetri)
{
	while (tetri->body[0] == '.' && tetri->body[1] == '.' &&
			tetri->body[2] == '.' && tetri->body[3] == '.')
		push(tetri, 1);
	while (tetri->body[0] == '.' && tetri->body[4] == '.' &&
			tetri->body[8] == '.' && tetri->body[12] == '.')
		push(tetri, 0);
}

static int	loop(int fd, t_tetri **tetri, int i)
{
	int		j;
	char	*line;
	int		rv;

	rv = get_next_line(fd, &line);
	if (rv == 0 || rv == -1 || ft_strlen(line) != 4 || *tetri == NULL)
		return (rv == 0 ? 0 : -1);
	j = 4;
	while (j--)
	{
		if (line[j] == '#' || line[j] == '.')
			(*tetri)->body[(i * 4) + j] =
			(line[j] == '.' ? '.' : (*tetri)->piece_id);
		else
			return (-1);
	}
	if (line)
		ft_strdel(&line);
	return (1);
}

static int	is_valid_tetri(t_tetri *tetri)
{
	int		blocks;
	int		connections;
	int		i;

	i = 0;
	blocks = 0;
	connections = 0;
	while (i < 16)
	{
		if (tetri->body[i] == tetri->piece_id)
		{
			blocks++;
			if (i >= 4 && tetri->body[i - 4] == tetri->piece_id)
				connections++;
			if (i % 4 != 0 && tetri->body[i - 1] == tetri->piece_id)
				connections++;
			if (i < 12 && tetri->body[i + 4] == tetri->piece_id)
				connections++;
			if (i % 4 != 3 && tetri->body[i + 1] == tetri->piece_id)
				connections++;
		}
		i++;
	}
	return (blocks == 4 && connections >= 6);
}

int			read_tetri(int fd, char piece_id, t_tetri **tetri)
{
	int		i;
	int		ret;

	*tetri = malloc(sizeof(t_tetri));
	i = -1;
	if (*tetri != NULL)
		(*tetri)->piece_id = piece_id;
	while (++i < 4)
	{
		if ((ret = loop(fd, tetri, i)) != 1)
			return (ret);
	}
	if (is_valid_tetri(*tetri))
	{
		align_tetri(*tetri);
		return (1);
	}
	else
		return (-1);
}
