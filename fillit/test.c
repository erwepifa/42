/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:07:03 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/25 12:04:16 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*ft_filltetri(t_tetri *t, int k, int nb_tetri
		, char *buffer)
{
	t[k].lettre = k + 'A';
	t[k].x = -5;
	t[k].y = -5;
	if (check_piece(buffer, 0))
		t = ft_place(check_piece(buffer, 0), t, nb_tetri, k);
	else
		t = ft_place2(check_piece2(buffer), t
				, nb_tetri, k);
	t[k].ysize = get_width(t[k]);
	t[k].xsize = ft_strlen(t[k].bloc[0]);
	return (t);
}

t_tetri			*ft_struct_filler(char *str, int nb_tetri)
{
	int			i[2];
	int			k;
	t_tetri		*t;
	static char	buffer[36] = {0};

	i[1] = 0;
	k = -1;
	if (!(t = (t_tetri *)malloc(sizeof(t_tetri) * (nb_tetri + 1))))
		return (NULL);
	while (++k < nb_tetri)
	{
		i[0] = 0;
		while (i[0] < 20)
		{
			buffer[i[0]] = str[i[1]];
			i[0]++;
			i[1]++;
		}
		buffer[20] = '\0';
		t = ft_filltetri(t, k, nb_tetri, buffer);
		i[1]++;
	}
	t[k].bloc = NULL;
	return (t);
}

int				get_width(t_tetri piece)
{
	int		i;

	i = 0;
	while (piece.bloc[i])
		i++;
	return (i);
}
