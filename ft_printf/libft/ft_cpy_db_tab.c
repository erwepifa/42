/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_db_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:12:27 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/15 21:12:43 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_cpy_db_tab(char **env)
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
