/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 18:18:31 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 18:18:43 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int character);
int					ft_isalpha(int character);
int					ft_isascii(int character);
int					ft_isdigit(int character);
int					ft_isprint(int character);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
						int c, size_t num);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *memptr1, const void *memptr2,
						size_t num);
void				*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, void *src, size_t count);
void				*ft_memset(void *memptr, int val, size_t num);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *destptr, const char *srcptr);
char				*ft_strchr(const char *str, int ch);
void				ft_strclr(char *s);
int					ft_strcmp(const char *string1, const char *string2);
char				*ft_strcpy(char *destptr, const char *srcptr);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *string);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *destptr, char *srcptr, size_t num);
int					ft_strncmp(const char *string1, const char *string2,
						size_t num);
char				*ft_strncpy(char *destptr, const char *srcptr, size_t num);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *string1, const char *string2,
						size_t len);
char				*ft_strrchr(const char *string, int symbol);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *string1, const char *string2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
