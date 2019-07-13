/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:54:38 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/13 23:31:41 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_verif(char *s, char *s2)
{
	int i;
	int o;

	o = 0;
	i = 0;
	while (s[i])
		i++;
	i--;
	if (s[i] == '=')
	{
		o = i + 1;
		if (s2[o] == '=')
			return (0);
		return (-1);
	}
	return (0);
}

char	*ft_souder(char *s1, char *s2, char *s3)
{
	char	*name;
	char	*ret;

	name = ft_strjoin2(s1, s3);
	ret = ft_strjoin(name, s2);
	ft_strdel(&name);
	return (ret);
}

char    **set_env(char **tab, char **env)
{
    int     i;
    char    *tmp;

    i = -1;
	if (!tab[1])
	{
		print_env(env);
		return (env);
	}
	if (!tab[2] || tab[3])
    {
        ft_error("usage: setenv [variable] [argument]", NULL);
        return (env);
    }
    while (env[++i])
    {
        if (ft_strnequ(tab[1], env[i], ft_strlen(tab[1])) == 1
		&& ft_verif(tab[1], env[i]) == 0)
        {
            ft_strdel(&env[i]);
            env[i] = ft_souder(tab[1], tab[2], "=");
            return (env);
        }
    }
    tmp = ft_souder(tab[1], tab[2], "=");
    env = malloc_setenv(env, tmp);
    free(tmp);
    return (env);
}

char 	**unset_env(char **tab, char **env)
{
	int 	i;
	int 	j;

	i = 1;
	j = 0;
	if (!tab[1])
	{
		ft_error("usage: unsetenv [variable ...]", NULL);
		return (env);
	}
	while (tab[i])
	{
		while (env[j])
		{
			if (ft_strnequ(tab[i], env[j], ft_strlen(tab[i])) == 1
				&& ft_verif(tab[1], env[i]) == 0)
				env = malloc_unsetenv(env, j);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (env);
}
