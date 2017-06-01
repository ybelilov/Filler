/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:44:46 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:44:50 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destptr, const char *srcptr)
{
	int i;
	int a;

	a = 0;
	i = 0;
	while (destptr[i])
		i++;
	while (srcptr[a] != '\0')
	{
		destptr[i] = srcptr[a];
		a++;
		i++;
	}
	destptr[i] = '\0';
	return (destptr);
}
