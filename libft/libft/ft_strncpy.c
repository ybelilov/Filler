/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:50:16 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:50:19 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destptr, const char *srcptr, size_t num)
{
	size_t i;

	i = 0;
	while (i < num && srcptr[i])
	{
		destptr[i] = srcptr[i];
		i++;
	}
	while (i < num)
	{
		destptr[i] = '\0';
		i++;
	}
	return (destptr);
}
