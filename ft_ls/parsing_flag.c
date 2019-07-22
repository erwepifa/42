/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing_Flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:48:13 by tescriva          #+#    #+#             */
/*   Updated: 2019/07/15 22:54:44 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flag_on(char c, int *flag)
{
	if (c == 'l' && flag[UN] == 0)
		flag[L] = 1;
	c == 'R' ? flag[BIG_R] = 1 : 0;
	c == 'a' ? flag[A] = 1 : 0;
	c == 'r' ? flag[R] = 1 : 0;
	c == 't' ? flag[T] = 1 : 0;
	c == 's' ? flag[S] = 1 : 0;
	if (c == '1')
	{
		flag[UN] = 1;
		flag[L] = 0;
	}
	c == 'd' ? flag[D] = 1 : 0;
	c == 'f' ? flag[F] = 1 : 0;
}

int		*ft_get_flag(char *str, int *flag)
{
	int i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == '-')
		return (flag);
	while (str[++i])
	{
		if (ft_chrstr("lRarts1df", str[i]) == 1)
			ft_flag_on(str[i], flag);
		else
			error(USAGE);
	}
	return (flag);
}
