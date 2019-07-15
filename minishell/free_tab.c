/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:35:05 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/15 21:26:28 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**free_all_tab(char **av)
{
	int i;

	i = 0;
	if (!av)
		return (NULL);
	while (av[i])
		ft_strdel(&av[i++]);
	free(av);
	av = NULL;
	return (av);
}
