/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 12:54:47 by tescriva          #+#    #+#             */
/*   Updated: 2019/07/22 21:14:43 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_file_acl(char *path)
{
	acl_t		tmp;
	char		buf[101];

	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		ft_putchar('+');
	}
	ft_putchar(' ');
}

void	ft_print_perm(t_lst *lst, t_ls *e)
{
	if (S_ISDIR(lst->val->stat.st_mode) || S_ISLNK(lst->val->stat.st_mode))
		ft_putchar(S_ISDIR(lst->val->stat.st_mode) ? 'd' : 'l');
	else
		ft_putchar('-');
	ft_printf("%c%c%c%c%c%c%c%c%c",
	lst->val->stat.st_mode & S_IRUSR ? 'r' : '-',
	lst->val->stat.st_mode & S_IWUSR ? 'w' : '-',
	lst->val->stat.st_mode & S_IXUSR ? 'x' : '-',
	lst->val->stat.st_mode & S_IRGRP ? 'r' : '-',
	lst->val->stat.st_mode & S_IWGRP ? 'w' : '-',
	lst->val->stat.st_mode & S_IXGRP ? 'x' : '-',
	lst->val->stat.st_mode & S_IROTH ? 'r' : '-',
	lst->val->stat.st_mode & S_IWOTH ? 'w' : '-',
	lst->val->stat.st_mode & S_IXOTH ? 'x' : '-');
	get_file_acl(lst->val->path);
	ft_print_info(lst, e);
}

void	ft_print_symbolic(t_lst *lst)
{
	char	*tmp;

	tmp = ft_memalloc(lst->val->stat.st_size + 5);
	if (readlink(lst->val->path, tmp, lst->val->stat.st_size))
		ft_printf("-> %s", tmp);
	ft_strdel(&tmp);
}

void	ft_print_data(t_lst *lst)
{
	time_t	today;
	char	*s;
	int		i;
	char	**result;

	time(&today);
	s = ctime(&(lst->val->stat.st_mtimespec.tv_sec)) + 4;
	result = ft_strsplit(s, ' ');
	ft_printf(" %s %2s %.5s ", result[0], result[1], result[2]);
	i = -1;
	while (result[++i])
		ft_strdel(&result[i]);
	free(result);
}

void	ft_padding_info(char *tmp, int size)
{
	int		length;

	length = size - ft_strlen(tmp);
	while (length >= 0)
	{
		ft_putchar(' ');
		length--;
	}
	ft_printf(tmp);
}

void	ft_print_info(t_lst *lst, t_ls *e)
{
	char	*tmp;

	tmp = ft_itoa(lst->val->stat.st_nlink);
	ft_padding_info(tmp, e->size[1]);
	ft_strdel(&tmp);
	ft_padding_info(lst->val->pw_name, e->size[2]);
	ft_strdel(&lst->val->pw_name);
	ft_padding_info(lst->val->gr_name, e->size[3]);
	ft_strdel(&lst->val->gr_name);
	tmp = ft_itoa(lst->val->stat.st_size);
	if (tmp[0] == '\0')
	{
		ft_strdel(&tmp);
		tmp = ft_strdup("0");
	}
	ft_padding_info(tmp, e->size[4]);
	ft_strdel(&tmp);
	ft_print_data(lst);
}
