/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:08:26 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/23 15:20:47 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_piece2(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '#')
		i++;
	if (str[i + 1] == '#' && str[i + 5] == '#' && str[i + 6] == '#')
		return (11);
	if (str[i + 1] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
		return (12);
	if (str[i + 5] == '#' && str[i + 6] == '#' && str[i + 11] == '#')
		return (13);
	if (str[i + 1] == '#' && str[i + 2] == '#' && str[i + 6] == '#')
		return (14);
	if (str[i + 5] == '#' && str[i + 6] == '#' && str[i + 10] == '#')
		return (15);
	if (str[i + 4] == '#' && str[i + 5] == '#' && str[i + 6] == '#')
		return (16);
	if (str[i + 4] == '#' && str[i + 5] == '#' && str[i + 10] == '#')
		return (17);
	if (str[i + 1] == '#' && str[i + 6] == '#' && str[i + 7] == '#')
		return (18);
	if (str[i + 4] == '#' && str[i + 5] == '#' && str[i + 9] == '#')
		return (19);
	return (0);
}

int		check_piece(char *str, int i)
{
	while (str[i] != '#')
		i++;
	if (str[i + 5] == '#' && str[i + 10] == '#' && str[i + 15] == '#')
		return (1);
	if (str[i + 1] == '#' && str[i + 2] == '#' && str[i + 3] == '#')
		return (2);
	if (str[i + 5] == '#' && str[i + 9] == '#' && str[i + 10] == '#')
		return (3);
	if (str[i + 1] == '#' && str[i + 2] == '#' && str[i + 7] == '#')
		return (4);
	if (str[i + 1] == '#' && str[i + 5] == '#' && str[i + 10] == '#')
		return (5);
	if (str[i + 5] == '#' && str[i + 6] == '#' && str[i + 7] == '#')
		return (6);
	if (str[i + 5] == '#' && str[i + 10] == '#' && str[i + 11] == '#')
		return (7);
	if (str[i + 5] == '#' && str[i + 4] == '#' && str[i + 3] == '#')
		return (8);
	if (str[i + 1] == '#' && str[i + 6] == '#' && str[i + 11] == '#')
		return (9);
	if (str[i + 1] == '#' && str[i + 2] == '#' && str[i + 5] == '#')
		return (10);
	return (0);
}

t_tetri	*ft_place2(int pc, t_tetri *t, int nb, int k)
{
	if (pc == 11)
		t[k].bloc = ft_strsplit("##|##", '|');
	else if (pc == 12)
		t[k].bloc = ft_strsplit(" ##|## ", '|');
	else if (pc == 13)
		t[k].bloc = ft_strsplit("# |##| #", '|');
	else if (pc == 14)
		t[k].bloc = ft_strsplit("###| # ", '|');
	else if (pc == 15)
		t[k].bloc = ft_strsplit("# |##|# ", '|');
	else if (pc == 16)
		t[k].bloc = ft_strsplit(" # |###", '|');
	else if (pc == 17)
		t[k].bloc = ft_strsplit(" #|##| #", '|');
	else if (pc == 18)
		t[k].bloc = ft_strsplit("## | ##", '|');
	else if (pc == 19)
		t[k].bloc = ft_strsplit(" #|##|# ", '|');
	if (t[k].bloc == NULL)
		ft_error(t, nb);
	return (t);
}

t_tetri	*ft_place(int pc, t_tetri *t, int nb, int k)
{
	if (pc == 1)
		t[k].bloc = ft_strsplit("#|#|#|#", '|');
	else if (pc == 2)
		t[k].bloc = ft_strsplit("####", '|');
	else if (pc == 3)
		t[k].bloc = ft_strsplit(" #| #|##", '|');
	else if (pc == 4)
		t[k].bloc = ft_strsplit("###|  #", '|');
	else if (pc == 5)
		t[k].bloc = ft_strsplit("##|# |# ", '|');
	else if (pc == 6)
		t[k].bloc = ft_strsplit("#  |###", '|');
	else if (pc == 7)
		t[k].bloc = ft_strsplit("# |# |##", '|');
	else if (pc == 8)
		t[k].bloc = ft_strsplit("  #|###", '|');
	else if (pc == 9)
		t[k].bloc = ft_strsplit("##| #| #", '|');
	else if (pc == 10)
		t[k].bloc = ft_strsplit("###|#  ", '|');
	if (t[k].bloc == NULL)
		ft_error(t, nb);
	return (t);
}
