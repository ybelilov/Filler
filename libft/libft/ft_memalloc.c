/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:37:50 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:37:54 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	mem = (char*)malloc(sizeof(char) * size);
	if (mem)
	{
		while (size)
		{
			mem[size - 1] = '\0';
			size--;
		}
		return (mem);
	}
	else
		return (NULL);
}
