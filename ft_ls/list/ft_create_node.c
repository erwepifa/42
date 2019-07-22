/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:55:44 by tescriva          #+#    #+#             */
/*   Updated: 2019/07/22 20:59:23 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_lst	*ft_list_add(t_lst **head, t_lst *lst, t_lst *tmp, int *flag)
{
	if (*head == NULL)
	{
		*head = tmp;
		return (*head);
	}
	return (ft_insert_node(head, lst, tmp, flag));
}

t_lst	*create_node(char *name, t_lst *lst, int *flag, t_ls *e, t_lst **head)
{
	t_info	*data;
	t_lst	*tmp;

	if ((data = (t_info*)malloc(sizeof(t_info))) == NULL
			|| (tmp = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	data->pw_name = NULL;
	data->gr_name = NULL;
	data->name = NULL;
	data->path = NULL;
	data->name = ft_strdup(name);
	data->path = ft_strjoin(e->current_path, data->name);
	if (lstat(data->path, &data->stat) == -1)
		return (NULL);
	if (flag[L] || flag[T])
	{
		if ((data->pw_name = ft_strdup(getpwuid(data->stat.st_uid)->pw_name))
				== NULL
			|| (data->gr_name = ft_strdup(getgrgid(data->stat.st_gid)->gr_name))
				== NULL)
			return (NULL);
		flag[T] ? data->clock = ctime(&data->stat.st_mtimespec.tv_sec) : 0;
	}
	tmp->val = data;
	tmp->next = NULL;
	e->total_block += tmp->val->stat.st_blocks;
	return (ft_list_add(head, lst, tmp, flag));
}
