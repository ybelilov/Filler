/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:40:17 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:40:21 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	size_t		i;
	char		*from;
	char		*to;

	i = 0;
	from = (char*)srcptr;
	to = (char*)destptr;
	while (i < num)
	{
		to[i] = from[i];
		i++;
	}
	return (destptr);
}
