/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:04:11 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/10 21:19:45 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include "libft/libft.h"

char	*ft_suppr_tab(char *line)
{
	int		i;
	char	*ret;

	i = 0;
	while (line[i])
	{
		if (line[i] < 32)
			line[i] = 32;
		i++;
	}
	i = 0;
	while (line[i] == 32)
		i++;
	ret = ft_strdup(line + i);
	ft_strdel(&line);
	return (ret);
}

int		ft_find_material(char *str)
{
	int i;
	int o;

	o = 0;
	i = 0;
	if (!str)
		return (0);
	if (ft_strequ(str, "\n") == 1)
		return (0);
	while (str[i])
	{
		if (str[i] > 32)
			o++;
		i++;
	}
    printf("%d\n", o);
	if (o > 0)
		return (1);
	return (0);
}

int     main(void)
{
    printf("%d\n", ft_find_material("tapute test"));
    return (0);
}
