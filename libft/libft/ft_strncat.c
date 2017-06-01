/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:49:37 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:49:41 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destptr, char *srcptr, size_t num)
{
	size_t i;
	size_t a;

	a = 0;
	i = 0;
	while (destptr[i])
		i++;
	while (srcptr[a] && a != num)
	{
		destptr[i] = srcptr[a];
		a++;
		i++;
	}
	destptr[i] = '\0';
	return (destptr);
}
