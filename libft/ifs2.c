/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifs2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:35:01 by ybelilov          #+#    #+#             */
/*   Updated: 2017/02/22 17:35:02 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if(t_form *form, int fw, char *cont, int pr)
{
	char *i;

	if ((size_t)form->fwidth > ft_strlen(cont) && form->flag[2] == '.')
		ft_if4(form, fw, cont, pr);
	else if ((size_t)form->fwidth > ft_strlen(cont) && form->flag[2] == '-')
	{
		i = ft_strnew(form->fwidth);
		while (--form->fwidth != -1)
			i[form->fwidth] = ' ';
		ft_memcpy(&i[0], &cont[0], ft_strlen(cont));
		form->content = i;
	}
	if (form->flag[4] == ' ' && (form->flag[2] == '-'
		|| ft_strrchr(" -+", form->content[0]) == NULL)
			&& form->flag[1] == '.' && (form->type == 'd' || form->type == 'i'))
	{
		form->content = ft_strjoin(ft_strcpy(ft_strnew(1), " "), form->content);
		if (form->content[ft_strlen(form->content) - 1] == ' '
				|| ft_ifzero(form) == 1)
			form->content[ft_strlen(form->content) - 1] = '\0';
	}
	ft_write(form->content, form);
}

void	ft_if4(t_form *form, int fw, char *cont, int pr)
{
	char *i;

	i = ft_strnew(form->fwidth);
	if (form->flag[0] == '.' || (pr != 0 && form->type != 's'))
		while (--form->fwidth != -1)
			i[form->fwidth] = ' ';
	else if (pr == 0 || form->type == 's')
	{
		while (--form->fwidth != -1)
			i[form->fwidth] = '0';
		if (form->content[0] == '-' || (form->content[0] == '+'
				&& form->flag[0] == '0'))
		{
			pr++;
			i[0] = form->content[0];
			cont[0] = '0';
		}
		if (form->flag[3] == '#' && form->flag[0] == '0')
		{
			i[1] = form->content[1];
			cont[1] = '0';
		}
	}
	ft_memcpy(&i[fw - ft_strlen(cont)], &cont[0], ft_strlen(cont));
	form->content = i;
}

int		ft_if7(t_form *form, intmax_t value)
{
	if (value == -9223372036854775807)
	{
		form->content = ft_strcpy(ft_strnew(20), "-9223372036854775807");
		return (0);
	}
	return (1);
}

void	ft_if8(t_form *form, intmax_t value, int base, char *s)
{
	if (value < 0 && base == 10)
	{
		s[0] = '-';
		form->flag[1] = '.';
	}
}
