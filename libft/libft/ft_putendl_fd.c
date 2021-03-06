/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:43:30 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:43:33 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char c;

	if (s)
	{
		while (*s)
		{
			c = *s;
			write(fd, &c, 1);
			s++;
		}
		write(fd, "\n", 1);
	}
}
