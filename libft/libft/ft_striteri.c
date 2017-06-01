/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:45:07 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:45:11 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int a;

	a = 0;
	if (s && f)
	{
		while (*s && s != NULL)
		{
			f(a, s);
			s++;
			a++;
		}
	}
	return ;
}
