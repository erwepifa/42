/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:24:25 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/10 22:55:52 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_suppr_tab(char *line)
{
	int		i;
	char	*ret;

	i = 0;
	while (line[i])
	{
		if (line[i] < 32)
			line[i] = 32;
		i++;
	}
	i = 0;
	while (line[i] == 32)
		i++;
	ret = ft_strdup(line + i);
	ft_strdel(&line);
	return (ret);
}

int		ft_find_material(char *str)
{
	int i;
	int o;

	o = 0;
	i = 0;
	if (!str)
		return (0);
	if (ft_strequ(str, "\n") == 1)
		return (0);
	while (str[i])
	{
		if (str[i] > 32)
			o++;
		i++;
	}
	if (o > 0)
		return (1);
	return (0);
}

char    **env_builtin(char **env, char **tab)
{
    char    **envv;

    envv = NULL;
    if (ft_strequ("setenv", *tab))
        env = set_env(tab, env);
	if (ft_strequ("unsetenv", *tab))
		env = unset_env(tab, env);
    return (env);
}

char    **check_builtin(char *line, char **env, char **tab)
{
    if (ft_strequ(line, "env"))
        print_env(env);
	if (ft_strequ(tab[0], "echo"))
		cmd_echo(tab);
    else
        env = env_builtin(env, tab);
    return (env);
}
