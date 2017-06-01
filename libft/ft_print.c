/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:32:29 by ybelilov          #+#    #+#             */
/*   Updated: 2017/02/21 15:32:30 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int(t_form *form)
{
	char *conv;
	char type;

	conv = form->conv;
	type = form->type;
	if (conv[0] == 'h' && conv[1] == 'h' && type != 'c' && type != 'D')
		ft_itoa_base_int((intmax_t)((signed char)va_arg(form->arg, int))
			, 10, form);
	else if (conv[0] == 'h' && conv[1] != 'h' && type != 'c' && type != 'D')
		ft_itoa_base_int((intmax_t)((short int)va_arg(form->arg, int))
			, 10, form);
	else if (conv[0] == 'l' && conv[1] == 'l' && type != 'c')
		ft_itoa_base_int((intmax_t)va_arg(form->arg, long long int), 10, form);
	else if ((conv[0] == 'l' && conv[1] != 'l' && type != 'c') || type == 'D')
		ft_itoa_base_int((intmax_t)va_arg(form->arg, long int), 10, form);
	else if (conv[0] == 'j' && type != 'c')
		ft_itoa_base_int(va_arg(form->arg, intmax_t), 10, form);
	else if (conv[0] == 'z' && type != 'c')
		ft_itoa_base_int((intmax_t)va_arg(form->arg, size_t), 10, form);
	else if (type != 'c' && type != 'C')
		ft_itoa_base_int((intmax_t)va_arg(form->arg, int), 10, form);
	else
		ft_if6(form, type, conv);
}

void	ft_uint(t_form *form)
{
	char	*conv;
	char	type;
	int		base;

	conv = form->conv;
	type = form->type;
	base = 10;
	if (type == 'o' || type == 'O')
		base = 8;
	else if (type == 'x' || type == 'X')
		base = 16;
	if (conv[0] == 'h' && conv[1] == 'h' && type != 'U' && type != 'O')
		ft_itoa_base_uint((size_t)(unsigned char)va_arg(form->arg, unsigned int)
			, base, form);
	else if (conv[0] == 'h' && conv[1] != 'h' && (type != 'U'))
		ft_itoa_base_uint((size_t)(unsigned short int)va_arg(form->arg
			, unsigned int), base, form);
	else if (conv[0] == 'l' && conv[1] == 'l')
		ft_itoa_base_uint((size_t)va_arg(form->arg
			, unsigned long long int), base, form);
	else
		ft_else(form, conv, type, base);
}

void	ft_str(t_form *form)
{
	if (form->type == 'S' || (form->type == 's' && form->conv[0] == 'l'
			&& form->conv[1] != 'l') || form->type == 's')
	{
		if (form->type == 's')
		{
			form->content = va_arg(form->arg, char*);
			if (form->content == NULL)
				form->content = ft_strcpy(ft_strnew(6), "(null)");
			if (form->prec == -1)
			{
				form->prec = 0;
				form->content = ft_strnew(1);
			}
		}
		else
			ft_wstr(va_arg(form->arg, wchar_t*), form);
	}
	else if (form->type == 'p')
	{
		ft_itoa_base_uint((size_t)va_arg(form->arg, size_t), 16, form);
		if (ft_strcmp(form->content, "0") == 0 && form->prec == -1)
			form->content[0] = '\0';
		form->type = 'x';
		form->flag[3] = '#';
	}
}

void	ft_form_print(t_form *form)
{
	char t;

	t = form->type;
	if (ft_strrchr("sSpdDioOuUxXcC", (int)form->type) == NULL)
	{
		form->content = ft_strnew(1);
		form->content[0] = form->type;
		if (form->type != '\0')
			ft_print_str(form);
	}
	ft_if5(form, t);
	if (t == 's' || t == 'S' || t == 'p')
	{
		ft_str(form);
		if (t == 's')
			ft_print_str(form);
		else if (t == 'p')
			ft_print_int(form);
	}
}
