/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:19:13 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/28 15:12:41 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_updategrid(char **grid, int size, t_tetri *piece, int nbr)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_memset(grid[i], '.', size);
		i++;
	}
	grid[i] = NULL;
	i = 0;
	while (i < nbr)
	{
		if (piece[i].x >= 0 && piece[i].y >= 0
				&& ft_pieceislegal(grid, piece[i], size))
			ft_insertpiece(grid, piece[i]);
		i++;
	}
}

void			ft_removepiece(char **grid, t_tetri *piece, int index, int nbr)
{
	int x;
	int y;

	x = piece[index].x;
	y = piece[index].y;
	piece[index].x = -5;
	piece[index].y = -5;
	ft_updategrid(grid, ft_strlen(grid[0]), piece, nbr);
	piece[index].x = x;
	piece[index].y = y;
}

int				ft_pieceislegal(char **grid, t_tetri piece, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < piece.ysize)
	{
		j = 0;
		if (piece.y + i >= size)
			return (0);
		while (j < piece.xsize)
		{
			if (piece.bloc[i][j] == '#'
					&& grid[piece.y + i][piece.x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
