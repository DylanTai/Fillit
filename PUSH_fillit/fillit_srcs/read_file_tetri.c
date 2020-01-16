/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jworden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:34:38 by jworden           #+#    #+#             */
/*   Updated: 2019/10/08 18:10:29 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetrimino.h"
#include <stdlib.h>
#include <fcntl.h>

int				read_file_tetri(char *name, t_list **out)
{
	t_tetri		*curr;
	int			file;
	int			rv;
	char		piece_id;

	file = open(name, O_RDONLY);
	if (file < 0)
		return (-1);
	piece_id = 'A';
	while ((rv = read_tetri(file, piece_id, &curr)))
	{
		if (rv == -1 || piece_id > 'Z')
		{
			close(file);
			return (-1);
		}
		ft_list_push_back(out, curr, sizeof(t_tetri));
		piece_id++;
		if ((rv = get_next_line(file, &name)) == 0)
			return (1);
		free(name);
	}
	close(file);
	return (rv == 0 ? -1 : 1);
}
