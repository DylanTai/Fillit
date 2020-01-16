/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:50:37 by dtai              #+#    #+#             */
/*   Updated: 2019/09/25 18:23:35 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Returns 1 if the "char" c is a form of whitespace, 0 elsewise.
*/

int	ft_iswhitespace(int c)
{
	return (((c >= 9 && c <= 13) || c == 32) ? 1 : 0);
}
