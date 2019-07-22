/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:59:52 by tescriva          #+#    #+#             */
/*   Updated: 2019/05/27 12:35:36 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_lst	*ft_delete_node(t_lst *lst)
{
	t_lst	*tmp;

	lst->val->path ? ft_strdel(&lst->val->path) : 0;
	lst->val->name ? ft_strdel(&lst->val->name) : 0;
	lst->val->pw_name ? ft_strdel(&lst->val->pw_name) : 0;
	lst->val->gr_name ? ft_strdel(&lst->val->gr_name) : 0;
	if (lst->next == NULL)
	{
		lst->val ? free(lst->val) : 0;
		lst ? free(lst) : 0;
		return (NULL);
	}
	else
	{
		tmp = lst->next;
		lst->val ? free(lst->val) : 0;
		free(lst->next);
		lst->next = NULL;
		lst ? free(lst) : 0;
	}
	return (tmp);
}
