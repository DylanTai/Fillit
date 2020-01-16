/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:36:57 by dtai              #+#    #+#             */
/*   Updated: 2019/11/01 16:40:34 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "tetrimino.h"

static int	check_legal(char *board, int pos[2], int size, t_tetri *piece)
{
	int	r_offset;
	int	c_offset;

	r_offset = -1;
	while (++r_offset <= piece->max_row)
	{
		c_offset = -1;
		while (++c_offset <= piece->max_col)
			if (piece->body[SQUARE(4, r_offset, c_offset)] == piece->piece_id
						&& (pos[0] + r_offset >= size ||
						pos[1] + c_offset >= size || board[SQUARE(size, pos[0]
						+ r_offset, pos[1] + c_offset)] != '.'))
				return (0);
	}
	return (1);
}

static char	*input_board(char *board, int pos[2], int size,
		t_list *pieces)
{
	char	*temp;
	int		itr;
	int		row_p;
	int		col_p;
	t_tetri	*piece;

	temp = (char *)malloc(sizeof(char) * (size * size));
	itr = -1;
	while (++itr < size * size)
		temp[itr] = board[itr];
	piece = (t_tetri *)(pieces->content);
	row_p = -1;
	while (++row_p <= piece->max_row)
	{
		col_p = -1;
		while (++col_p <= piece->max_col)
			if (piece->body[SQUARE(4, row_p, col_p)] != '.')
				temp[SQUARE(size, pos[0] + row_p, pos[1] + col_p)] =
						piece->piece_id;
	}
	return (temp);
}

static char	free_board(char **board, int *size, t_list *pieces, int cont)
{
	if (*board)
		free(*board);
	*board = NULL;
	if (cont)
	{
		*size += 1;
		return (find_smallest_square(board, size, pieces, 1));
	}
	return (0);
}

static char	*init_board(int size)
{
	char	*temp;
	int		itr;

	temp = (char *)malloc(sizeof(char) * (size * size));
	itr = -1;
	while (++itr < size * size)
		temp[itr] = '.';
	return (temp);
}

int			find_smallest_square(char **board, int *size, t_list *pieces,
				int first)
{
	int		pos[2];
	char	*prev;

	if (!pieces)
		return (1);
	if (!*board)
		*board = init_board(*size);
	pos[0] = -1;
	while (++pos[0] < *size)
	{
		pos[1] = -1;
		while (++pos[1] < *size)
			if (check_legal(*board, pos, *size, (t_tetri *)(pieces->content)))
			{
				prev = *board;
				*board = input_board(*board, pos, *size, pieces);
				if (find_smallest_square(board, size, pieces->next, 0))
					return (free_board(&prev, size, pieces, 0) + 1);
				free_board(board, size, pieces, 0);
				*board = prev;
			}
	}
	if (first)
		return (free_board(board, size, pieces, 1));
	return (0);
}
