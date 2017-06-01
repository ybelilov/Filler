/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:52:55 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:52:59 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	stop;
	char	*str;

	if (!s)
	{
		str = ft_strnew(0);
		return (str);
	}
	start = 0;
	stop = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if ((stop + 1) == start)
	{
		str = ft_strnew(0);
		return (str);
	}
	while (s[stop] == ' ' || s[stop] == '\t' || s[stop] == '\n')
		stop--;
	str = ft_strsub(s, start, stop - start + 1);
	if (!str)
		return (NULL);
	return (str);
}
