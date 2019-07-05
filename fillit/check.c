/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:51:48 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/28 14:36:18 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char *str, int tetri)
{
	int				i;
	int				j;
	static char		buffer[36] = {0};

	j = 0;
	while (tetri--)
	{
		i = 0;
		while (i < 20)
			buffer[i++] = str[j++];
		buffer[20] = '\0';
		if (nb_tetri(buffer) != 1)
			return (0);
		if (!check_piece(buffer, 0) && !check_piece2(buffer))
			return (0);
		j++;
	}
	return (1);
}
