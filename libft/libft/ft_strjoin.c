/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:47:50 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:47:55 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *q;

	if (s1 && s2)
	{
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!str)
			return (NULL);
		str = ft_strcpy(str, s1);
		q = ft_strcpy(&str[ft_strlen(s1)], s2);
		return (str);
	}
	return (NULL);
}
