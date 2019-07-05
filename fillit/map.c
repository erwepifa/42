/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:22:44 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/28 15:42:37 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_initgrid(int size, int nbr, t_tetri *piece)
{
	char	**grid;
	int		i;

	i = 0;
	if (!(grid = (char**)malloc((size + 1) * sizeof(char*))))
		return (NULL);
	while (i < size)
	{
		if (!(grid[i] = (char*)ft_memalloc((size + 1) * sizeof(char))))
		{
			free_map(grid);
			return (NULL);
		}
		ft_memset(grid[i], '.', size);
		i++;
	}
	grid[i] = NULL;
	i = 0;
	while (i < nbr)
	{
		piece[i].x = -5;
		piece[i].y = -5;
		i++;
	}
	return (grid);
}

int				nb_tetri(char *str)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			n++;
		i++;
	}
	return (n / 4);
}

static int		ft_sqrt(int nb)
{
	int s;

	if (nb < 0)
	{
		return (0);
	}
	s = 0;
	while ((s <= (nb / 2) + 1) && (s < 46341))
	{
		if ((s * s) >= nb)
		{
			return (s);
		}
		s++;
	}
	return (0);
}

static int		ft_validitytest(int *size, t_tetri *piece, char **grid, int k)
{
	if (k >= size[1])
		return (1);
	piece[k].x = 0;
	piece[k].y = 0;
	while (piece[k].y + piece[k].ysize <= size[0])
	{
		while (piece[k].x + piece[k].xsize <= size[0])
		{
			if (ft_pieceislegal(grid, piece[k], size[0]))
			{
				ft_updategrid(grid, size[0], piece, size[1]);
				if (ft_validitytest(size, piece, grid, k + 1))
					return (1);
				ft_removepiece(grid, piece, k, size[1]);
			}
			(piece[k].x)++;
		}
		(piece[k].y)++;
		piece[k].x = 0;
	}
	return (0);
}

void			ft_fillit_res(t_tetri *piece, int nbr)
{
	char	**grid;
	int		size;
	int		t[2];

	size = ft_sqrt(4 * nbr);
	if (!(grid = ft_initgrid(size, nbr, piece)))
		ft_error(piece, nbr);
	t[0] = size;
	t[1] = nbr;
	while (!(ft_validitytest(t, piece, grid, 0)))
	{
		size++;
		t[0] = size;
		free_map(grid);
		if (!(grid = ft_initgrid(size, nbr, piece)))
			ft_error(piece, nbr);
	}
	ft_print_tab(grid);
	free_map(grid);
	freepiece(piece, nbr);
}
