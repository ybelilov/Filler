/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:38:03 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:39:53 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	char		val;

	str = (const char*)s;
	val = (char)c;
	while (n--)
	{
		if (val == *str)
			return ((void*)str++);
		str++;
	}
	return (NULL);
}
