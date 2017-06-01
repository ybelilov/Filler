/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:50:43 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/28 16:50:46 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	if (!content)
	{
		p->content = NULL;
		p->content_size = 0;
		p->next = NULL;
	}
	else
	{
		p->content = ft_memcpy(malloc(content_size), content, content_size);
		p->content_size = content_size;
		p->next = NULL;
	}
	return (p);
}
