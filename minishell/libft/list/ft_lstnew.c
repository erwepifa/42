/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:44:16 by tescriva          #+#    #+#             */
/*   Updated: 2019/07/13 22:56:41 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n;

	n = (t_list*)malloc(sizeof(*n));
	if (!n)
		return (NULL);
	if (!content)
	{
		n->content = NULL;
		n->content_size = 0;
		n->next = NULL;
		return (n);
	}
	n->content = (t_list*)malloc(sizeof(*n->content) * content_size + 1);
	if (!n->content)
		return (NULL);
	ft_memcpy(n->content, content, content_size);
	n->content_size = content_size;
	n->next = NULL;
	return (n);
}
