/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:34:54 by ybelilov          #+#    #+#             */
/*   Updated: 2017/02/22 17:34:56 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if6(t_form *form, char type, char *conv)
{
	form->content = ft_strnew(1);
	form->prec = 0;
	if ((conv[0] == 'l' && conv[1] != 'l' && type == 'c') || (type == 'C'))
		form->content[0] = (char)va_arg(form->arg, wchar_t);
	else
		form->content[0] = (char)va_arg(form->arg, int);
	if (form->content[0] == 0)
	{
		form->prec = 0;
		form->fwidth == 0 ? 0 : form->fwidth--;
		form->ret++;
		form->flag[4] = 'Z';
		form->type = 'c';
	}
}

void	ft_else(t_form *form, char *conv, char type, int base)
{
	if ((conv[0] == 'l' && conv[1] != 'l') || (type == 'O' || type == 'U'))
		ft_itoa_base_uint((size_t)va_arg(form->arg
			, unsigned long int), base, form);
	else if (conv[0] == 'j' && type != 'c')
		ft_itoa_base_uint((size_t)va_arg(form->arg, uintmax_t), base, form);
	else if (conv[0] == 'z' && type != 'c')
		ft_itoa_base_uint((size_t)va_arg(form->arg, size_t), base, form);
	else
		ft_itoa_base_uint((size_t)va_arg(form->arg, unsigned int), base, form);
}

void	ft_if5(t_form *form, char t)
{
	if (t == 'd' || t == 'i' || t == 'c' || t == 'D' || t == 'C')
	{
		ft_int(form);
		ft_ifnullint(form);
		ft_print_int(form);
	}
	if (t == 'u' || t == 'o' || t == 'x' || t == 'X' || t == 'U' || t == 'O')
	{
		ft_uint(form);
		ft_ifnullint(form);
		ft_print_int(form);
	}
}

void	ft_ifnullint(t_form *form)
{
	if (form->content[0] == '0' && form->content[1] == '\0' && form->prec == -1
			&& (form->type == 'o' || form->type == 'O') && form->flag[3] == '#')
	{
		form->prec = 0;
	}
	if (form->content[0] == '0' && form->content[1] == '\0' && form->prec == -1)
	{
		form->flag[3] = '.';
		form->prec = 0;
		form->content[0] = '\0';
	}
	if (form->content[0] == '0' && form->content[1] == '\0')
		form->flag[3] = '.';
}

void	ft_if2(t_form *form)
{
	if (form->conv[2] <= '4')
	{
		if (*(form->str + 1) == 'l')
		{
			form->str++;
			if (form->conv[2] != '4')
			{
				form->conv[1] = 'l';
				form->conv[2] = '3';
			}
			else
				form->conv[2] = '4';
		}
		else
			form->conv[2] = '4';
		form->conv[0] = 'l';
	}
	else
		*(form->str + 1) == 'l' ? form->str++ : 0;
}
