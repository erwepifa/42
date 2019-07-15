/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:02:46 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/23 15:02:35 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*str;

	str = NULL;
	if (!(str = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	str->next = NULL;
	if (content != NULL)
	{
		str->content = ft_memalloc(content_size);
		if (!str->content)
			return (NULL);
		str->content = ft_memmove(str->content, content, content_size);
		str->content_size = content_size;
	}
	else
	{
		str->content = NULL;
		str->content_size = 0;
	}
	return (str);
}
