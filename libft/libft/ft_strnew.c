/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:50:43 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:50:49 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * size + 1);
	if (res)
	{
		size++;
		while (size)
		{
			res[size - 1] = '\0';
			size--;
		}
		return (res);
	}
	return (NULL);
}
