/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:41:39 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/28 15:10:31 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(char **grid)
{
	int i;

	if (grid)
	{
		i = 0;
		while (grid[i])
		{
			free(grid[i]);
			i++;
		}
		free(grid);
	}
}

void	freepiece(t_tetri *piece, int nb)
{
	int		i;

	i = 0;
	while (i < nb && piece[i].bloc != NULL)
	{
		free_map(piece[i].bloc);
		i++;
	}
	free(piece);
}
