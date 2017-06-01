/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:52:15 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:52:19 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *string1, const char *string2)
{
	int i;
	int a;

	i = 0;
	if (!*string2)
		return ((char*)string1);
	while (string1[i])
	{
		a = 0;
		while (string1[i + a] == string2[a] && string2[a] && string1[i + a])
			a++;
		if (string2[a] == '\0')
			return ((char*)&string1[i]);
		i++;
	}
	return (NULL);
}
