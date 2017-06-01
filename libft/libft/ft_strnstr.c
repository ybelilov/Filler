/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:50:57 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:51:02 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *string1, const char *string2, size_t len)
{
	size_t i;
	size_t a;

	i = 0;
	while (string1[i] && i != len)
	{
		a = 0;
		while (string1[i + a] == string2[a] && string2[a]
				&& string1[i + a] && (i + a) != len)
			a++;
		if (string2[a] == '\0')
			return ((char*)&string1[i]);
		i++;
	}
	return (NULL);
}
