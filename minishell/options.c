/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:24:25 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/13 23:56:18 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		i;
	int		o;
	char	*p;

	o = 0;
	i = 0;
	if (!(s1) || (!(s2)))
		return (NULL);
	while (s1[i])
		i++;
	while (s2[o])
		o++;
	if (!(p = (char*)malloc(sizeof(*p) * (i + o) + 1)))
		return (NULL);
	i = 0;
	o = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[o])
		p[i++] = s2[o++];
	p[i] = '\0';
	return (p);
}

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
    char    **cmd;

    cmd = NULL;
	if (ft_strequ("unsetenv", *tab))
		env = unset_env(tab, env);
	else if (ft_strequ("setenv", *tab) == 1)
		env = set_env(tab, env);
	else
	{
		cmd = exec_final(cmd, env, tab);
		if (cmd)
			free_all_tab(cmd);
	}
    return (env);
}

char    **check_builtin(char *line, char **env, char **tab)
{
    if (ft_strequ(line, "env"))
        print_env(env);
	else if (ft_strequ(tab[0], "echo"))
		cmd_echo(tab);
	else if (ft_strequ(tab[0], "cd"))
		run_cd(line, env, tab);
    else
        env = env_builtin(env, tab);
    return (env);
}
