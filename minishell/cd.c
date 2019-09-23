/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 20:37:54 by erwepifa          #+#    #+#             */
/*   Updated: 2019/09/11 12:01:07 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**check_pwd_for_cd(char **env)
{
	int		i;
	char	*buf;
	char	*tmp;

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

char	**check_oldpwd_for_cd(char **env)
{
	int		i;
	char	*buf;
	char	*tmp;

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

char	**get_oldpwd(char **env, char *str)
{
	int		i;

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

char	**check_cd_home(char **env)
{
	int		i;

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

char	**cmd_cd(char **env)
{
	int		i;
	char	*str;
	char	*buf;

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
