/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:36:41 by tescriva          #+#    #+#             */
/*   Updated: 2019/07/22 20:51:05 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error(int err)
{
	if (err == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-alRrtdG1Ss] [file ...]", 2);
	}
	exit(1);
}

int *ft_size_zero(int *tab)
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	return (tab);
}

int		*ft_init_flag(void)
{
	int		*flag;

	flag = (int*)malloc(sizeof(int) * 10);
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	flag[4] = 0;
	flag[5] = 0;
	flag[6] = 0;
	flag[7] = 0;
	flag[8] = 0;
	flag[9] = 0;
	return (flag);
}

int		*ft_init_size(void)
{
	int		*tab;

	tab = (int*)malloc(sizeof(int) * 6);
	return (ft_size_zero(tab));
}

DIR		*ft_isdir(char *path)
{
	struct stat st;
	DIR			*dossier;

	if ((dossier = opendir(path)) == NULL)
		return (NULL);
	stat(path, &st);
	if (S_ISDIR(st.st_mode) == 1)
		return (dossier);
	return (NULL);
}

int		ft_start(char **av, int ac, t_ls *e, t_lst *lst, int *flag)
{
	int		i;

	e->head = NULL;
	e->current_path = NULL;
	e->recur = 0;
	lst = ft_memalloc(sizeof(t_lst));
	i = av[1] ? 1 : 0;
	while (av[i] && av[i][0] == '-' && av[i][1] != '-')
	{
		flag = ft_get_flag(av[i], flag);
		i++;
	}
	//ft_printf("%s", av[i]);
	av[i] && av[i][0] == '-' && av[i][1] == '-' ? i++ : 0;
	e->size = ft_init_size();
	if (ac >= i && av[i] && av[i + 1])
	{
		while (av[i])
		{
			//if ((e->path = ft_isdir(path)) != NULL)
			ft_printf("%s:\n", av[i]);
			e->main_path = ft_strdup(av[i]);
			ft_get_folder(flag, e, lst, e->main_path);
			av[i + 1] ? ft_printf("\n") : 0;
			e->head = NULL;
			ft_strdel(&e->main_path);
			e->current_path = NULL;
			i++;
		}
	}
	else
	{
		//ft_printf("%s", av[i]);
		e->main_path = !av[i] || av[i][0] == '-' || i == 0 ? ft_strdup("."): ft_strdup(av[i]) ;
		ft_get_folder(flag, e, lst, e->main_path);
	}
	free(flag);
	free(e->size);
	ft_strdel(&e->main_path);
	free(lst);
	return (1);
}

int		main(int ac, char **av)
{
	t_ls	e;
	t_lst	lst;

	ft_start(av, ac, &e, &lst, ft_init_flag());
	return (0);
}
