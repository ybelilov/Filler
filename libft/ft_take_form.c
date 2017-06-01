/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:33:01 by ybelilov          #+#    #+#             */
/*   Updated: 2017/02/21 15:33:03 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_take_flag(t_form *form)
{
	form->flag == NULL ? form->flag = ft_strcpy(ft_strnew(5), ".....") : 0;
	if (*form->str == '0')
		form->flag[0] = '0';
	else if (*form->str == '+')
		form->flag[1] = '+';
	else if (*form->str == '-')
		form->flag[2] = '-';
	else if (*form->str == '#')
		form->flag[3] = '#';
	else if (*form->str == ' ')
		form->flag[4] = ' ';
	else
		return (0);
	form->str++;
	return (1);
}

int		ft_take_fwidth(t_form *form)
{
	int i;

	i = ft_atoi(form->str);
	if (i == 0 || *form->str == '0' || *form->str == '+'
			|| *form->str == '-' || *form->str == ' ')
		return (0);
	form->fwidth = i;
	while (i > 0)
	{
		form->str++;
		i /= 10;
	}
	return (1);
}

int		ft_take_prec(t_form *form)
{
	int i;

	if (*form->str == '.')
	{
		form->str++;
		form->prec = ft_atoi(form->str);
		if (form->prec == 0 && (*form->str <= '0' || *form->str > '9'))
		{
			form->prec = -1;
			if (*form->str == '0')
				form->str++;
			return (1);
		}
		i = form->prec;
		while (i > 0)
		{
			form->str++;
			i /= 10;
		}
		return (1);
	}
	return (0);
}

int		ft_take_conv(t_form *form)
{
	form->conv == NULL ? form->conv = ft_strnew(3) : 0;
	if (*form->str == 'h')
		ft_if1(form);
	else if (*form->str == 'l')
		ft_if2(form);
	else if (*form->str == 'j')
	{
		if (form->conv[2] <= '5')
		{
			form->conv[0] = 'j';
			form->conv[2] = '5';
		}
	}
	else if (*form->str == 'z')
	{
		if (form->conv[2] <= '6')
		{
			form->conv[0] = 'z';
			form->conv[2] = '6';
		}
	}
	else
		return (0);
	form->str++;
	return (1);
}

void	ft_if1(t_form *form)
{
	if (form->conv[2] <= '2')
	{
		if (*(form->str + 1) == 'h')
		{
			form->str++;
			if (form->conv[2] != '2')
			{
				form->conv[1] = 'h';
				form->conv[2] = '1';
			}
			else
				form->conv[2] = '2';
		}
		else
			form->conv[2] = '2';
		form->conv[0] = 'h';
	}
	else
		*(form->str + 1) == 'h' ? form->str++ : 0;
}
