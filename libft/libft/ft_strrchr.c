/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:51:20 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:51:22 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	int i;

	i = ft_strlen(string);
	if (symbol == '\0')
	{
		return ((char *)&string[i]);
	}
	while (--i >= 0)
		if (string[i] == symbol)
			return ((char *)&string[i]);
	return (NULL);
}
