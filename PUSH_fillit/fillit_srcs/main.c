/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:13:25 by dtai              #+#    #+#             */
/*   Updated: 2019/11/01 16:41:51 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "tetrimino.h"

/*
** poses[0] = row_itr, poses[1] = col_itr, pos[2] = max_row, pos[3] = max_col
** and are iterated in the main function to pass Norm
*/

static void	fix_list_maxes(t_list **begin_list, int poses[6])
{
	t_list	*temp;

	temp = *begin_list;
	while (temp)
	{
		poses[0] = -1;
		poses[2] = 0;
		poses[3] = 0;
		while (++poses[0] < 4)
		{
			poses[1] = -1;
			while (++poses[1] < 4)
			{
				if (((t_tetri *)(temp->content))->
						body[SQUARE(4, poses[0], poses[1])] != '.')
				{
					poses[2] = poses[0] > poses[2] ? poses[0] : poses[2];
					poses[3] = poses[1] > poses[3] ? poses[1] : poses[3];
				}
			}
		}
		((t_tetri *)(temp->content))->max_row = poses[2];
		((t_tetri *)(temp->content))->max_col = poses[3];
		temp = temp->next;
	}
}

/*
** poses[0] to poses[3] are just intialized to pass Norm in fix_list
** poses[4] = size and poses[5] = itr, used to pass the Norm as well
*/

int			main(int argc, char **argv)
{
	t_list	*list;
	char	*board;
	int		poses[6];

	list = NULL;
	if (argc != 2 || read_file_tetri(argv[1], &list) != 1)
	{
		if (argc != 2)
			ft_putstr("usage: ./fillit source_file\n");
		else
			ft_putstr("error\n");
		return (-1);
	}
	fix_list_maxes(&list, poses);
	poses[4] = 2;
	board = NULL;
	find_smallest_square(&board, &poses[4], list, 1);
	poses[5] = -1;
	while (++poses[5] < poses[4] * poses[4])
	{
		ft_putchar(board[poses[5]]);
		if (!((poses[5] + 1) % poses[4]))
			ft_putchar('\n');
	}
	return (0);
}
