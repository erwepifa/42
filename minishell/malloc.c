/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:43:13 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/13 23:39:16 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **malloc_setenv(char **env, char *tab)
{
    char **ret;
    int     i;

    i = -1;
    while (env[++i])
        ;
    if (!(ret = (char**)malloc(sizeof(char*) * (i + 2))))
        return (NULL);
    ret[i + 1] = 0;
    i = 0;
    while (env[i])
	{
        ret[i] = ft_strdup(env[i]);
		i++;
	}
    ret[i++] = ft_strdup(tab);
    free(env);
    return (ret);
}

char    **malloc_unsetenv(char **env, int value)
{
    char    **ret;
    int     i;
    int     j;

    i = -1;
    j = 0;
    while (env[++i])
        ;
    if (!(ret = (char**)malloc(sizeof(char*) * i)))
        return (NULL);
    i = 0;
    while (i < value)
        ret[j++] = ft_strdup(env[i++]);
    if (env[i])
        i++;
    while (env[i])
        ret[j++] = ft_strdup(env[i++]);
    ret[j] = 0;
    free(env);
    return (ret);
}
