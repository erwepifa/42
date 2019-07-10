/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:43:43 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/10 21:23:01 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_check_str(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char    **check_path(char **env)
{
    int     i;
    char    **envv;

    i = -1;
    if (!env || env[i] == 0)
        return (NULL);
    while (env[++i] && ft_strncmp(env[++i], "PATH=", 5) != 0)
        ;
    envv = ft_strsplit(&env[i][5], ':');
    return (envv);
}

int     check_tab(char **tab)
{
    if (access(*tab, F_OK) == -1)
    {
        printf("minishell: command not found: ");
        return (-1);
    }
    if (access(*tab, F_OK) == -1)
    {
        printf("minishell: permission denied: ");
        return (-1);
    }
    return (0);
}

int     run_cmd(char *name, char **env, char **tab)
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        if (execve(name, tab, env) == -1)
            return (-1);
        return (0);
    }
    else
        wait(&pid);
    return (0);
}
