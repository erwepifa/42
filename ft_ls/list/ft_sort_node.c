/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:54:46 by tescriva          #+#    #+#             */
/*   Updated: 2019/07/22 20:57:19 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		ft_sort_wich_side(t_info *a, t_info *b, int *flag)
{
	if (flag[R])
	{
		if (flag[T])
		{
			if (a->stat.st_mtimespec.tv_sec == b->stat.st_mtimespec.tv_sec)
				return (ft_strcmp(a->name, b->name) > 0 ? -1 : 1);
			return (a->stat.st_mtimespec.tv_sec > b->stat.st_mtimespec.tv_sec ? 1 : -1);
		}
		return (ft_strcmp(a->name, b->name) <= 0 ? 1 : -1);
	}
	if (flag[T])
	{
		if (a->stat.st_mtimespec.tv_sec == b->stat.st_mtimespec.tv_sec)
		{
			if (a->stat.st_mtimespec.tv_nsec == b->stat.st_mtimespec.tv_nsec)
				return (ft_strcmp(a->name, b->name) >= 0 ? 1 : -1);
			return (a->stat.st_mtimespec.tv_nsec > b->stat.st_mtimespec.tv_nsec ? -1 : 1);
		}
		return (a->stat.st_mtimespec.tv_sec > b->stat.st_mtimespec.tv_sec ? -1 : 1);
	}
	if (ft_strcmp(a->name, b->name) >= 0)
		return (1);
	return (-1);
}

t_lst	*ft_sort_reverse(t_lst **head, t_lst *lst, t_lst *insert, t_lst *prev, int *flag)
{
	if (ft_sort_wich_side(lst->val, insert->val, flag) == 1)
	{
		*head = insert;
		insert->next = lst;
		return (*head);
	}
	while (lst->next)
	{
		prev = lst;
		lst = lst->next;
		if (ft_sort_wich_side(prev->val, insert->val, flag) == -1
				&& ft_sort_wich_side(lst->val, insert->val, flag) == 1)
		{
			if (*head == prev)
			{
				*head = insert;
				insert->next = prev;
				return (*head);
			}
			insert->next = lst;
			prev->next = insert;
			return (*head);
		}
	}
	lst->next = insert;
	return (*head);
}

t_lst	*ft_insert_node(t_lst **head, t_lst *lst, t_lst *insert, int *flag)
{
	t_lst	*prev;

	lst = *head;
	prev = NULL;
	if (ft_sort_wich_side(lst->val, insert->val, flag) == 1)
	{
		insert->next = lst;
		*head = insert;
		return (*head);
	}
	while (lst->next)
	{
		prev = lst;
		lst = lst->next;
		if (ft_sort_wich_side(prev->val, insert->val, flag) == -1 && ft_sort_wich_side(lst->val, insert->val, flag) == 1)
		{
			if (*head == prev)
			{
				prev->next = insert;
				insert->next = lst;
			}
			else
			{
				insert->next = lst;
				prev->next = insert;
			}
			return (*head);
		}
	}
	lst->next = insert;
	return (*head);
}
