/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:50:08 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:50:10 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	size_t i;

	i = 0;
	while (string1[i] == string2[i] && string1[i] && string2[i] && i < num)
		i++;
	if (i == num)
		return ((unsigned char)string1[i - 1] - (unsigned char)string2[i - 1]);
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
