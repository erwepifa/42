/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:31:35 by tescriva          #+#    #+#             */
/*   Updated: 2019/07/22 20:57:46 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_list(t_lst *lst, t_ls *e, int *flag)
{
	char	*tmp;

	if ((flag[L] || flag[S]) && e->total_block != 0)
		ft_printf("total %d\n", e->total_block);
	if (flag[D])
	{
		ft_putstr(CYAN_L);
		ft_printf("%s\n", e->main_path);
		exit(1);
	}
	lst = e->head;
	while (lst)
	{
		e->recur == 0 && S_ISDIR(lst->val->stat.st_mode) ? e->recur = 1 : 0;
		if (flag[S])
		{
			tmp = ft_itoa(lst->val->stat.st_blocks);
			tmp[0] == '\0' ? ft_strdel(&tmp) : 0;
			tmp = NULL ? tmp = ft_strdup("0") : 0;
			ft_padding_info(tmp, e->size[0]);
			ft_strdel(&tmp);
		}
		flag[L] ? ft_print_perm(lst, e) : 0;
		ft_print_color(lst);
		flag[L] && S_ISLNK(lst->val->stat.st_mode) ? ft_print_symbolic(lst) : 0;
		flag[L] || flag[UN] ? ft_putchar('\n') : 0;
		lst = lst->next;
	}
}
