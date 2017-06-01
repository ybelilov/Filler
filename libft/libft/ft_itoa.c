/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:36:58 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:37:02 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_size(long int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void			ft_rec(char *str, long int num, int i)
{
	if (num >= 10)
	{
		ft_rec(str, num / 10, i - 1);
		ft_rec(str, num % 10, i);
	}
	if (num < 10)
	{
		str[i - 1] = num + 48;
	}
}

char				*ft_itoa(int n)
{
	long int	num;
	char		*res;
	int			size;

	num = n;
	if (n == 0 || n == -0)
	{
		res = ft_strnew(1);
		if (!res)
			return (NULL);
		res[0] = '0';
		return (res);
	}
	size = ft_size(num);
	res = ft_strnew(size);
	if (!res)
		return (NULL);
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	ft_rec(res, num, size);
	return (res);
}
