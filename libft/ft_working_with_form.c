/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_working_with_form.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:33:10 by ybelilov          #+#    #+#             */
/*   Updated: 2017/02/21 15:33:11 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_form		*ft_form_cretor(void)
{
	t_form	*form;

	form = malloc(sizeof(t_form));
	form->type = 0;
	form->flag = NULL;
	form->fwidth = 0;
	form->prec = 0;
	form->conv = NULL;
	form->content = NULL;
	form->ret = 0;
	form->end = 1;
	return (form);
}

void		ft_form_clean(t_form *form)
{
	form->type = 0;
	form->flag = NULL;
	form->fwidth = 0;
	form->prec = 0;
	form->conv = NULL;
	form->content = NULL;
}

void		ft_form_format(t_form *form)
{
	int ret;

	ret = 1;
	while (ret != 0 && *form->str != '\0')
		ret = ft_take_prec(form) + ft_take_fwidth(form)
				+ ft_take_flag(form) + ft_take_conv(form);
	form->type = *form->str;
	if (form->type != '\0')
		form->str++;
}
