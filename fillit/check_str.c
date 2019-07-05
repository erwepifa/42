/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:44:24 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/28 14:38:27 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			expected_nb_tetri(char *str)
{
	int			len;
	static int	nb[3] = {0};

	len = (int)ft_strlen(str);
	if (len == 20)
		return (1);
	if (len == 0 || (len - 20) % 21 != 0 || len > 545)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			++nb[0];
		else if (*str == '#')
			++nb[1];
		else if (*str == '.')
			++nb[2];
		else
			return (0);
		str++;
	}
	if (nb[1] + nb[2] + nb[0] != len ||
			(nb[2] != 3 * nb[1]))
		return (0);
	return (nb[1] / 4);
}

int			check_grid(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (((i + 1 - ((i + 1) / 21)) % 5) == 0 && str[i] != '\n')
			return (0);
		if (((i + 1 - ((i + 1) / 21)) % 5) != 0 && str[i] != '#'
				&& str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

t_tetri		*input_checker(char *file)
{
	t_tetri		*piece;
	char		*str;
	int			nb_tetris;
	static char	s[546] = {0};

	if (!(str = gnl(file)))
		return (NULL);
	if (!ft_strlen(str))
	{
		free(str);
		return (NULL);
	}
	ft_strcpy(s, str);
	free(str);
	if (!(nb_tetris = expected_nb_tetri(s)))
		return (NULL);
	if (!(check_grid(s)))
		return (NULL);
	if (!(ft_check(s, nb_tetris)))
		return (NULL);
	if (!(piece = ft_struct_filler(s, nb_tetris)))
		return (NULL);
	return (piece);
}
