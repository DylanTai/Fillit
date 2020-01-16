/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:35:42 by dtai              #+#    #+#             */
/*   Updated: 2019/10/05 16:55:52 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	store_line(const int fd, char **line, char **next_line,
			int full_line)
{
	char	*temp;
	int		i;

	if (ft_strchr(next_line[fd], '\n'))
	{
		i = 0;
		while (next_line[fd][i] != '\n')
			i++;
		*line = ft_strsub(next_line[fd], 0, i);
		temp = ft_strdup(next_line[fd] + i + 1);
		free(next_line[fd]);
		next_line[fd] = temp;
		if (next_line[fd][0] == '\0')
			ft_strdel(&next_line[fd]);
	}
	else
	{
		if (full_line)
			return (0);
		*line = ft_strdup(next_line[fd]);
		ft_strdel(&next_line[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*next_line[MAX_FD + 1];
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	char		*temp;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!next_line[fd])
			next_line[fd] = ft_strnew(0);
		temp = ft_strjoin(next_line[fd], buffer);
		free(next_line[fd]);
		next_line[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (!next_line[fd] || next_line[fd][0] == '\0'))
		return (0);
	return (store_line(fd, line, next_line, ret == BUFF_SIZE ? 1 : 0));
}
