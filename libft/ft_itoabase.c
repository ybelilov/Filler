/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:32:20 by ybelilov          #+#    #+#             */
/*   Updated: 2017/02/21 15:32:21 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_base_int(intmax_t value, int base, t_form *form)
{
	int			i;
	intmax_t	n;
	char		*s;
	char		*hex;

	hex = "0123456789ABCDEF";
	if (ft_if7(form, value) == 0)
		return ;
	i = (value < 0 && base == 10) ? 2 : 1;
	n = value;
	while (n /= base)
		i++;
	s = (char*)malloc(sizeof(char) * i + 1);
	s[i] = 0;
	ft_if8(form, value, base, s);
	value == 0 ? s[0] = '0' : 0;
	n = value;
	while (n)
	{
		s[--i] = hex[(n < 0) ? -(n % base) : n % base];
		n /= base;
	}
	form->content = s;
}

void	ft_itoa_base_uint(size_t value, int base, t_form *form)
{
	int		i;
	size_t	n;
	char	*s;
	char	*hex;

	hex = "0123456789ABCDEF";
	i = 1;
	n = value;
	while (n /= base)
		i++;
	s = (char*)malloc(sizeof(char) * i + 1);
	s[i] = 0;
	if (value == 0)
		s[0] = '0';
	n = value;
	while (n)
	{
		s[--i] = hex[n % base];
		n /= base;
	}
	form->content = s;
}

void	ft_print_str(t_form *form)
{
	char	*cont;
	int		fw;

	fw = form->fwidth;
	if (form->prec != 0 && ft_strlen(form->content) > (size_t)form->prec)
		form->content = ft_strsub(form->content, 0, form->prec);
	cont = form->content;
	form->type = 's';
	ft_if(form, fw, cont, form->prec);
}

void	ft_print_int(t_form *form)
{
	char	*s;
	int		pr;
	char	*cont;
	int		fw;

	cont = form->content;
	fw = form->fwidth;
	pr = form->prec;
	if (ft_strlen(form->content) <= (size_t)form->prec && form->prec != -1)
	{
		s = ft_strnew(form->prec);
		while (--form->prec != -1)
			s[form->prec] = '0';
		if (form->content[0] == '-')
		{
			pr++;
			cont[0] = '0';
			s[0] = '-';
		}
		ft_memcpy(&s[pr - ft_strlen(cont)], &cont[0], ft_strlen(cont));
		form->content = s;
	}
	ft_someflags(form);
	cont = form->content;
	ft_if(form, fw, cont, pr);
}

int		ft_ifzero(t_form *form)
{
	char *s;

	s = form->content;
	while (*s == ' ')
		s++;
	while (*s == '0')
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}
