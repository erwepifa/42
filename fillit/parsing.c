/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:02:57 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/17 16:13:40 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_contact(char *str, int x, int count, int n)
{
	while (str[x] != '\0')
	{
		count = 0;
		while (x < ((19 * n + n * 2) - 2))
		{
			if (str[x] == '#')
			{
				if ((x + 1) <= ((19 * n + n * 2) - 2) && str[x + 1] == '#')
					count++;
				if ((x - 1) >= (19 * n + n + n - 21) && str[x - 1] == '#')
					count++;
				if ((x + 5) <= ((19 * n + n * 2) - 2) && str[x + 5] == '#')
					count++;
				if ((x - 5) >= (19 * n + n + n - 21) && str[x - 5] == '#')
					count++;
			}
			x++;
		}
		x++;
		n++;
		if (count != 6 && count != 8)
			return (0);
	}
	return (1);
}

int		check_hash(char *str)
{
	int		i;
	int		x;

	x = 0;
	while (str[x] != '\0')
	{
		i = 0;
		while (str[x] != '\n' || (str[x + 1] == '#' || str[x + 1] == '.'))
		{
			if (str[x] == '#')
				i++;
			x++;
		}
		if (i != 4)
			return (0);
		x++;
	}
	return (check_contact(str, 0, i, 1));
}

int		check_bn(char *str)
{
	int		x;
	int		i;

	i = 1;
	x = 0;
	while (str[x] != '\0')
	{
		while (str[x] == '#' || str[x] == '.')
			x++;
		if (str[x] == '\n' && str[x + 1] == '\n')
		{
			if (i != 4)
				return (0);
			i = 1;
			x += 2;
		}
		if (str[x] == '\n')
		{
			x++;
			i++;
		}
	}
	return (check_hash(str));
}

int		check_all(char *str, int tetra)
{
	int		i;
	int		car;

	i = 0;
	if (tetra > 26)
		return (0);
	while (str[i] != '\0')
	{
		car = 0;
		while (str[i] == '#' || str[i] == '.')
		{
			i++;
			car++;
		}
		if (str[i] == '\n')
			i++;
		else
			return (0);
		if (car != 4 && (car != 0 && str[i] != '\n' && str[i + 1] != '\n'))
			return (0);
	}
	return (check_bn(str));
}
