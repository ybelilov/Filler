/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:37:34 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:37:39 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
			int c, size_t num)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*to;

	i = 0;
	from = (unsigned char*)src;
	to = (unsigned char*)dst;
	while (i < num)
	{
		to[i] = from[i];
		if (from[i] == (unsigned char)c)
			return (dst + 1 + i);
		i++;
	}
	return (NULL);
}
