/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:59:06 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/24 15:50:18 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_insertpiece(char **grid, t_tetri piece)
{
	int		i;
	int		j;

	i = 0;
	while (piece.bloc[i])
	{
		j = 0;
		while (piece.bloc[i][j])
		{
			if (piece.bloc[i][j] == '#')
				grid[piece.y + i][piece.x + j] = piece.lettre;
			j++;
		}
		i++;
	}
}
