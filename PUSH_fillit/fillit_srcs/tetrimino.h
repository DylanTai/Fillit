/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jworden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:58:03 by jworden           #+#    #+#             */
/*   Updated: 2019/10/17 21:30:24 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

# include "libft.h"

# define SQUARE(s, r, c) ((c) + ((s) * (r)))

typedef struct	s_tetri
{
	char		body[16];
	char		piece_id;
	int			max_row;
	int			max_col;
}				t_tetri;

int				read_tetri(int fd, char piece_id, t_tetri **tetri);
int				read_file_tetri(char *filename, t_list **out);
void			free_tetri(t_tetri **tetri);
int				find_smallest_square(char **board, int *size, t_list *pieces,
					int first);

#endif
