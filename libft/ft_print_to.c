/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:32:38 by ybelilov          #+#    #+#             */
/*   Updated: 2017/02/21 15:32:40 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_to(t_form *form)
{
	while (*form->str && *form->str != '%')
	{
		write(1, &(*form->str), 1);
		form->str++;
		form->ret++;
	}
	if (*form->str == '\0')
		form->end = 0;
	else if (*(form->str + 1) == '%')
	{
		write(1, &(*form->str), 1);
		form->ret++;
		form->str += 2;
		ft_print_to(form);
	}
}

void	ft_write(char *str, t_form *form)
{
	while (*str && form->ret != 2147483647)
	{
		write(1, &(*str), 1);
		str++;
		form->ret++;
	}
	if (form->type == 'c' && form->flag[4] == 'Z')
	{
		write(1, "\0", 1);
	}
	if (form->ret == 2147483647)
		form->end = 0;
}

void	ft_someflags(t_form *form)
{
	char	*s;
	size_t	i;

	i = -1;
	if (form->flag[3] == '#' && (form->type == 'x' || form->type == 'X'))
		ft_if3(form);
	if (form->flag[3] == '#' && (form->type == 'o' || form->type == 'O')
		&& form->content[0] != '0')
	{
		s = ft_strnew(ft_strlen(form->content) + 1);
		s[0] = '0';
		ft_strcpy(&s[1], form->content);
		ft_memdel((void**)&form->content);
		form->content = s;
	}
	if (form->flag[1] != '.' && (form->type == 'd' || form->type == 'i'))
	{
		s = ft_strnew(ft_strlen(form->content) + 1);
		s[0] = form->flag[1];
		ft_strcpy(&s[1], form->content);
		ft_memdel((void**)&form->content);
		form->content = s;
	}
	while (form->type == 'x' && ++i != ft_strlen(form->content))
		form->content[i] = ft_tolower(form->content[i]);
}

void	ft_if3(t_form *form)
{
	char *s;

	s = ft_strnew(ft_strlen(form->content) + 2);
	s[0] = '0';
	s[1] = 'X';
	ft_strcpy(&s[2], form->content);
	ft_memdel((void**)&form->content);
	form->content = s;
}
