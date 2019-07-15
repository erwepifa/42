/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 20:37:54 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/15 21:05:22 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **check_pwd_for_cd(char **env)
{
    int     i;
    char    *buf;
    char    *tmp;

    i = -1;
    buf = NULL;
    if ((buf = getcwd(buf, 0)) == NULL)
        return (NULL);
    while (env[++i])
    {
        if (ft_strnequ(env[i], "PWD=", 4) == 1)
        {
            free(env[i]);
            env[i] = ft_strjoin("PWD=", buf);
            ft_strdel(&buf);
            return (env);
        }
    }
    tmp = ft_strjoin("PWD=", buf);
    env = malloc_setenv(env, tmp);
    ft_strdel(&tmp);
    ft_strdel(&buf);
    return (env);
}

char    **check_oldpwd_for_cd(char **env)
{
    int     i;
    char    *buf;
    char    *tmp;

    i = -1;
    buf = NULL;
    if ((buf = getcwd(buf, 0)) == NULL)
        return (NULL);
    while (env[++i])
    {
        if (ft_strnequ(env[i], "OLDPWD=", 7) == 1)
        {
            free(env[i]);
            env[i] = ft_strjoin("OLDPWD=", buf);
            ft_strdel(&buf);
            return (env);
        }
    }
    tmp = ft_strjoin("OLDPWD=", buf);
    env = malloc_setenv(env, tmp);
    ft_strdel(&tmp);
    ft_strdel(&buf);
    return (env);
}

char    **get_oldpwd(char **env, char *str)
{
    int     i;

    i = -1;
    while (env[++i])
    {
        if (ft_strnequ(env[i], "OLDPWD=", 7) == 1)
        {
            ft_strdel(&env[i]);
            env[i] = ft_strdup(str);
            return (env);
        }
    }
    return (malloc_setenv(env, str));
}

char    **check_cd_home(char **env)
{
    int     i;

    i = -1;
    while (env[++i])
    {
        if (ft_strnequ(env[i], "HOME=", 5) == 1)
        {
            chdir(&env[i][5]);
            env = check_pwd_for_cd(env);
            return (env);
        }
    }
    ft_putendl("error");
    return (env);
}

char    **cmd_cd(char **env)
{
    int     i;
    char    *str;
    char    *buf;

    buf = NULL;
    i = -1;
    if ((buf = getcwd(buf, 0)) == NULL)
        return (NULL);
    while (env[++i])
    {
        if (ft_strnequ(env[i], "OLDPWD=", 7) == 1)
        {
            str = ft_strjoin("OLDPWD=", buf);
            chdir(&env[i][7]);
            ft_putendl(&env[i][7]);
            env = get_oldpwd(env, str);
            ft_strdel(&str);
            env = check_pwd_for_cd(env);
            ft_strdel(&buf);
            return (env);
        }
    }
    env = check_oldpwd_for_cd(env);
    env = check_pwd_for_cd(env);
    return (env);
}

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

int     access_cd(char *str, char **tab)
{
    int     i;
    char    *var;

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

char    **run_cd(char *str, char **env, char **tab)
{
    int     i;
    char    *tmp;

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
