/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:31:56 by ybelilov          #+#    #+#             */
/*   Updated: 2017/02/21 15:32:01 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *restrict format, ...)
{
	t_form	*form;

	form = ft_form_cretor();
	form->str = (char*)format;
	va_start(form->arg, format);
	while (form->end)
	{
		ft_print_to(form);
		if (form->end)
		{
			form->str++;
			ft_form_format(form);
			ft_form_print(form);
			ft_form_clean(form);
		}
		if (!(form->end))
			break ;
	}
	va_end(form->arg);
	return (form->ret);
}
