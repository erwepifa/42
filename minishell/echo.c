/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:45:20 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/15 22:00:43 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_echo(char **tab)
{
	int		i;

	i = 1;
	while (tab[i])
	{
		if (ft_strequ(tab[i], "~"))
		{
			ft_putstr("/Users/erwepifa");
			break ;
		}
		ft_putstr(tab[i]);
		if (tab[++i])
			ft_putstr(" ");
	}
	ft_putendl("");
}
