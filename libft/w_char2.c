/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_char2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 12:19:02 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/10 12:19:03 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wchar_len(wchar_t c)
{
	if (c > 0 && c < 127)
		return (1);
	else if (c > 128 && c < 2047)
		return (2);
	else if (c > 2048 && c < 65535)
		return (3);
	else if (c > 65536 && c < 2097151)
		return (4);
	else if (c > 2097152 && c < 67108863)
		return (5);
	else
		return (6);
}

int		ft_power(int num, size_t pw)
{
	if (pw == 0)
		return (1);
	return (num * ft_power(num, pw - 1));
}
