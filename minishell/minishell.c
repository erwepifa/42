/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:34:06 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/13 23:50:32 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_env(char **tab)
{
    int     i;

    i = -1;
    while (tab[++i])
        ft_putendl(tab[i]);
}

char    *get_user(char **env)
{
    int     i;
    char    *str;

    i = -1;
    while (env[++i])
    {
        if (ft_strnequ(env[i], "USER=", 5) == 1)
        {
            if (!(str = ft_strdup(ft_strrchr(env[i], '=') + 1)))
                return (NULL);
            return (str);
        }
    }
    return (NULL);
}

char    *get_pwd(char **env)
{
    int     i;
    char    *str;

    i = -1;
    while (env[++i])
    {
        if (ft_strnequ(env[i], "PWD=", 4))
        {
            if (ft_strrchr(env[i], '/') == NULL)
				return (NULL);
            if (!(str = ft_strdup(ft_strrchr(env[i], '/') + 1)))
                return (NULL);
            return (str);
        }
    }
    return (NULL);
}

void    write_prompt(char **env)
{
    char    *pwd;
    char    *user;

    user = get_user(env);
    pwd = get_pwd(env);
    ft_putstr("\x1B[32;1m");
    ft_putstr(user ? user : "");
    ft_putstr("\x1B[31;1m");
    write(1, " :", 2);
    ft_putstr("\x1B[96;1m ");
    ft_putstr(pwd ? pwd : "");
    ft_putstr("\x1B[31;1m");
    write(1, " >", 2);
    ft_putstr("\x1B[0m ");
    if (user)
        free(user);
    if (pwd)
        free(pwd);
}

void    print_minishell(char **env)
{
    char    **tab;
    char    *line;

    line = ft_strdup("");
    tab = NULL;
    char *tmp = "minishell";
    while (1)
    {
        write_prompt(env);
        get_next_line(0, &line);
        printf("%s\n", line);
        line = ft_suppr_tab(line);
        tab = ft_strsplit(line, ' ');
        if (ft_strequ(*tab, "exit"))
        {
            ft_strdel(&line);
            free_all_tab(tab);
            free_all_tab(env);
            exit(0);
        }
        if (ft_find_material(line) == 1)
            env = check_builtin(line, env, tab);

        ft_strdel(&line);
        printf("%s\n", line);
        free_all_tab(tab);
    }
    free_all_tab(env);
}
