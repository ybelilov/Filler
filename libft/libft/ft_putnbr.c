/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:43:44 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:43:49 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		n = n * (-1);
		ft_putchar('-');
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
		return ;
	}
	if (n > 2147483647 || n < -2147483648)
		return ;
	ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
	return ;
}
