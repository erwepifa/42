/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   folder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:33:45 by tescriva          #+#    #+#             */
/*   Updated: 2019/07/22 20:53:11 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_size(t_lst *lst, t_ls *e)
{
	int		length;

	if ((length = ft_intlen(lst->val->stat.st_blocks)) > e->size[0])
		e->size[0] = length;
	if ((length = ft_intlen(lst->val->stat.st_nlink)) > e->size[1])
		e->size[1] = length;
	if ((length = ft_strlen(lst->val->pw_name)) > e->size[2])
		e->size[2] = length;
	if ((length = ft_strlen(lst->val->gr_name)) > e->size[3])
		e->size[3] = length;
	if ((length = ft_intlen(lst->val->stat.st_size)) > e->size[4])
		e->size[4] = length;
}

char	*ft_check_path(t_ls *e, char *path)
{
	if ((e->path = ft_isdir(path)) == NULL)
	{
		ft_printf("ft_ls: %s: No such file or directory\n", path);
		return (NULL);
	}
	if (e->current_path == NULL)
	{
		if (e->main_path[0] == '/' && e->main_path[1] == '\0')
			return (ft_strdup(e->main_path));
		return (ft_strjoin(e->main_path, "/"));
	}
	return (ft_strjoinfree(e->current_path, "/"));
}

void	ft_get_folder(int *flag, t_ls *e, t_lst *lst, char *path)
{
	e->total_block = 0;
	e->size = ft_size_zero(e->size);
	if ((e->current_path = ft_check_path(e, path)) == NULL)
		return ;
	while ((e->dir = readdir(e->path)) != NULL)
	{
		if (e->dir->d_name[0] != '.' || (e->dir->d_name[0] == '.'
					&& flag[A]) || flag[F])
		{
			lst = create_node(e->dir->d_name, lst, flag, e, &e->head);
			if (flag[L] && e->total_block != 0)
				ft_get_size(lst, e);
		}
	}
	closedir(e->path);
	ft_display_ls(e, e->head, flag);
	ft_strdel(&e->current_path);
}
