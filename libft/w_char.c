/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:39:28 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/09 13:39:29 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tocharstr(wchar_t *str, t_form *form)
{
	wchar_t	*string;
	char	*w_char;
	char	*res;
	int		prec;

	string = (wchar_t*)str;
	res = ft_strnew(1);
	prec = 0;
	while (*string)
	{
		w_char = ft_w_char_to_char(*string);
		if ((form->prec && (int)(prec + ft_strlen(w_char))
				<= (int)form->prec) || !form->prec)
			res = ft_strjoin(res, w_char);
		else
			break ;
		prec += ft_strlen(w_char);
		free(w_char);
		string++;
	}
	return (res);
}

char	*ft_w_char_to_char(wchar_t w_char)
{
	size_t	len;
	size_t	i;
	char	*wchar;

	len = ft_wchar_len(w_char);
	wchar = ft_strnew(len + 1);
	if (len == 1)
	{
		*wchar = (char)w_char;
		return (wchar);
	}
	i = len;
	while (i)
	{
		if (i != 1)
		{
			*(wchar + (i - 1)) = w_char % 64 + 128;
			w_char >>= 6;
		}
		i--;
	}
	*wchar = ft_power(2, 8) - ft_power(2, 8 - len) + w_char;
	return (wchar);
}

void	ft_wstr(wchar_t *w_char, t_form *form)
{
	if (w_char == NULL || form->prec == -1)
	{
		if (w_char == NULL)
			form->content = ft_strcpy(ft_strnew(6), "(null)");
		if (form->prec == -1)
		{
			form->prec = 0;
			form->content = ft_strnew(1);
		}
		ft_print_str(form);
	}
	else
	{
		form->content = ft_tocharstr(w_char, form);
		ft_wwidth(form, -1);
		ft_write(form->content, form);
	}
}

void	ft_wwidth(t_form *form, int i)
{
	char	*res;
	char	c;

	if ((size_t)form->fwidth > ft_strlen(form->content))
	{
		res = ft_strnew(form->fwidth);
		c = ' ';
		i = -1;
		if (form->flag[2] == '-')
		{
			while (++i < form->fwidth)
				res[i] = c;
			ft_memcpy(&res[0], &form->content[0], ft_strlen(form->content));
		}
		else
		{
			if (form->flag[0] == '0')
				c = '0';
			while (++i < form->fwidth)
				res[i] = c;
			ft_strcpy(&res[form->fwidth - ft_strlen(form->content)],
					&form->content[0]);
		}
		form->content = res;
	}
}
