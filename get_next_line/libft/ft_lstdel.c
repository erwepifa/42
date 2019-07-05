/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:03:36 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/23 15:23:11 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_del(t_list *el, void (*del)(void *, size_t))
{
	if (el->next != NULL)
		ft_del(el->next, del);
	del(el->content, el->content_size);
	free(el);
}

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !del)
		return ;
	if (!alst[0])
		return ;
	ft_del(alst[0], del);
	alst[0] = NULL;
}
