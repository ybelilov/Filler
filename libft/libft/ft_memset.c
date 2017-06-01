/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:40:59 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:41:02 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	size_t			i;
	unsigned char	*b;

	i = 0;
	b = (unsigned char*)memptr;
	while (i != num)
	{
		b[i] = val;
		i++;
	}
	return (memptr);
}
