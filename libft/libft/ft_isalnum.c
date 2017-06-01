/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:35:29 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:35:36 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if ((character >= 65 && character <= 90) ||
			(character >= 97 && character <= 122) ||
				(character >= 48 && character <= 57))
		return (1);
	else
		return (0);
}
