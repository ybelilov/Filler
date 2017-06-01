/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:40:43 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:40:49 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t count)
{
	char	*dest1;
	char	*src1;

	dest1 = (char*)dest;
	src1 = (char*)src;
	if (src1 > dest1)
	{
		ft_memcpy(dest1, src1, count);
		return (dest);
	}
	else
	{
		dest1 += count - 1;
		src1 += count - 1;
		while (count)
		{
			*dest1-- = *src1--;
			count--;
		}
		return (dest);
	}
}
