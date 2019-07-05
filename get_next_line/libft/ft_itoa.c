/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:26:23 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/22 12:21:45 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*dst;
	int			count;
	int			i;
	long int	nb;

	nb = n;
	count = ft_count(n);
	i = 0;
	if (nb < 0 || count == 0)
		count++;
	if (!(dst = ft_strnew(count)))
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		dst[0] = '-';
		i++;
	}
	while (count > i)
	{
		count--;
		dst[count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dst);
}
