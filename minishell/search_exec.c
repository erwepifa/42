/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:01:08 by erwepifa          #+#    #+#             */
/*   Updated: 2019/09/11 12:01:08 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_error(char *s1, char *name)
{
	if (!s1)
		return (-1);
	ft_putstr_fd(s1, 2);
	if (name)
		ft_putstr_fd(name, 2);
	ft_putchar_fd('\n', 2);
	return (-1);
}

int		access_cd(char *str, char **tab)
{
	int		i;
	char	*var;

	i = -1;
	if (str[2] && str[2] != ' ')
		ft_putstr("minishell: command not found: ");
	if (!tab[1])
		return (0);
	if (tab[2])
		ft_putstr("cd: too many arguments");
	if (ft_strequ(tab[1], "-") == 0 && ft_strequ(tab[1], "~") == 0)
	{
		if ((var = access_dir(tab[1])) != NULL)
			return (ft_error(var, str));
	}
	return (0);
}

char	**run_cd(char *str, char **env, char **tab)
{
	int		i;
	char	*tmp;

	i = -1;
	if (access_cd(str, tab) == -1)
		return (env);
	if (ft_strequ(tab[1], "-") == 1)
		return (cmd_cd(env));
	env = check_oldpwd_for_cd(env);
	if (!tab[1] || ft_strequ(tab[1], "~") == 1)
		return (check_cd_home(env));
	chdir(tab[1]);
	env = check_pwd_for_cd(env);
	return (env);
}
