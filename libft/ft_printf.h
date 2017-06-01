/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:32:08 by ybelilov          #+#    #+#             */
/*   Updated: 2017/02/21 15:32:10 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_from
{
	char		type;
	char		*flag;
	int			fwidth;
	int			prec;
	char		*conv;
	va_list		arg;
	char		*content;
	int			ret;
	int			end;
	char		*str;
}				t_form;

int				ft_printf(const char *restrict format, ...);
t_form			*ft_form_cretor(void);
void			ft_form_clean(t_form *form);
void			ft_print_to(t_form *form);
void			ft_form_format(t_form *form);
int				ft_take_flag(t_form *form);
int				ft_take_fwidth(t_form *form);
int				ft_take_prec(t_form *form);
int				ft_take_conv(t_form *form);
void			ft_itoa_base_int(intmax_t value, int base, t_form *form);
void			ft_itoa_base_uint(size_t value, int base, t_form *form);
void			ft_int(t_form *form);
void			ft_uint(t_form *form);
void			ft_str(t_form *form);
void			ft_form_print(t_form *form);
void			ft_write(char *str, t_form *form);
void			ft_form_clean(t_form *form);
void			ft_print_str(t_form *form);
void			ft_print_int(t_form *form);
void			ft_if(t_form *form, int fw, char *cont, int pr);
void			ft_someflags(t_form *form);
void			ft_ifnullint(t_form *form);
int				ft_ifzero(t_form *form);
void			ft_if1(t_form *form);
void			ft_if2(t_form *form);
void			ft_if3(t_form *form);
void			ft_if4(t_form *form, int fw, char *cont, int pr);
void			ft_else(t_form *form, char *conv, char type, int base);
void			ft_if5(t_form *form, char t);
void			ft_if6(t_form *form, char type, char *conv);
int				ft_if7(t_form *form, intmax_t value);
void			ft_if8(t_form *form, intmax_t value, int base, char *s);
char			*ft_tocharstr(wchar_t *str, t_form *form);
char			*ft_w_char_to_char(wchar_t w_char);
void			ft_wstr(wchar_t *w_char, t_form *form);
size_t			ft_wchar_len(wchar_t c);
int				ft_power(int num, size_t pw);
void			ft_wwidth(t_form *form, int i);
#endif
