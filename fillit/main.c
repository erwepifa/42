/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:38:59 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/28 15:42:54 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putendl(tab[i]);
		i++;
	}
}

static int	illegalchar(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] != '#' && buffer[i] != '\n' && buffer[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

char		*gnl(char *file)
{
	int		ret;
	int		fd;
	char	buffer[BUFF_SIZE + 1];
	char	*str_input;
	char	*stock;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	if (!(str_input = ft_strnew(1)))
		return (NULL);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		if (!(stock = ft_strjoin(str_input, buffer)))
			return (NULL);
		free(str_input);
		if (!illegalchar(buffer))
		{
			free(stock);
			return (NULL);
		}
		str_input = stock;
	}
	close(fd);
	return (str_input);
}

int			main(int argc, char **argv)
{
	t_tetri		*piece;
	int			i;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}
	if (!(piece = input_checker(argv[1])))
	{
		ft_putstr("error\n");
		return (0);
	}
	i = 0;
	while (piece[i].bloc)
		i++;
	ft_fillit_res(piece, i);
	return (0);
}
