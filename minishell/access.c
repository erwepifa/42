/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 23:22:03 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/10 23:39:44 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *access_dir(char *str)
{
    struct  stat    f;

    lstat(str, &f);
    if (access(str, F_OK) == -1)
        return ("cd: no such file or directory: ");
    else if (access(str, X_OK) == -1)
    {
        if (S_ISDIR(f.st_mode) != 1)
            return ("cd: not a directory: ");
        return ("cd: permission denied: ");
    }
    if (S_ISDIR(f.st_mode) != 1)
        return ("cd: not a directory: ");
    return (NULL);
}

int     search_exec(char *cmd, char *tab)
{
    DIR     *dir;
    struct  dirent *g;

    dir = opendir(cmd);
    if (dir)
    {
        while ((g = readdir(dir)) != NULL)
        {
            if (ft_strequ(g->d_name, tab))
            {
                closedir(dir);
            }
        }
    }
    if (dir)
        closedir(dir);
    return (-1);
}

char    *parsing_cmd(char   **cmd, char **tab)
{
    int     i;
    int     j;
    int     access;

    i = 0;
    j = -1;
    access = 0;
    *tab = NULL;
    if (!cmd)
    {
        ft_putstr("minishell: command not found: ");
        return (NULL);
    }
    if (j == -1)
    {
        ft_putstr("minishell: command not found: ");
        return (NULL);
    }
    else if (j == 2)
        return (NULL);
    return (cmd[i - 1]);
}
