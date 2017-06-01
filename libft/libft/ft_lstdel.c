/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:05:33 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/29 16:05:35 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;

	while (*alst)
	{
		p = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = p;
	}
	*alst = NULL;
}
