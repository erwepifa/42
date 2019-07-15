/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:39:13 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/13 23:59:53 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
static char		**ft_cpy_db_tab(char **env)
{
	char	**ret;
	int		i;
	int		o;

	o = 0;
	i = 0;
	while (env[i])
		i++;
	if (!(ret = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (env[i])
		ret[o++] = ft_strdup(env[i++]);
	ret[o] = 0;
	return (ret);
}
*/
int     main(int ac, char **av, char **env)
{
    char **envd;

    (void)ac;
    (void)av;
    envd = ft_cpy_db_tab(env);
    print_minishell(envd);
    return (0);

}
