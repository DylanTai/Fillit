/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:36:03 by dtai              #+#    #+#             */
/*   Updated: 2019/09/17 17:51:03 by dtai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	output;
	size_t	j;
	size_t	k;

	output = 0;
	while (src[output] != '\0')
		output++;
	if (dstsize == 0)
		return (output);
	j = 0;
	while (dst[j] != '\0')
	{
		if (j < dstsize)
			output++;
		j++;
	}
	k = 0;
	while (j < dstsize - 1 && src[k] != '\0')
	{
		dst[j] = src[k];
		j++;
		k++;
	}
	dst[j] = '\0';
	return (output);
}
