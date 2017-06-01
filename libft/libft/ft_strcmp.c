/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:46:08 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:46:11 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *string1, const char *string2)
{
	size_t i;

	i = 0;
	while (string1[i] == string2[i] && string1[i] && string2[i])
		i++;
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
