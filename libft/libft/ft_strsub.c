/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:52:36 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:52:40 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (s)
	{
		str = ft_strnew(len);
		if (!(str))
			return (NULL);
		str = ft_strncpy(str, &s[start], len);
		return (str);
	}
	return (NULL);
}
