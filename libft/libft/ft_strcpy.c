/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:56:09 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:56:13 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destptr, const char *srcptr)
{
	int i;

	i = 0;
	while (srcptr[i])
	{
		destptr[i] = srcptr[i];
		i++;
	}
	destptr[i] = '\0';
	return (destptr);
}
