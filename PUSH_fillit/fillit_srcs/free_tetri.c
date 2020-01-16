/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jworden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:34:53 by jworden           #+#    #+#             */
/*   Updated: 2019/10/05 15:47:28 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "tetrimino.h"

void	free_tetri(t_tetri **tetri)
{
	if (tetri != NULL && *tetri != NULL)
	{
		free((*tetri)->body);
		free(*tetri);
		*tetri = NULL;
	}
}
