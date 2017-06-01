/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:40:03 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:40:07 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	unsigned char *string1;
	unsigned char *string2;

	string1 = (unsigned char*)memptr1;
	string2 = (unsigned char*)memptr2;
	while (num)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
		num--;
	}
	return (0);
}
