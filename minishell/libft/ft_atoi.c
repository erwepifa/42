/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:46:14 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/28 15:33:08 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

int		ft_atoi(const	char *str)
{
	int	result;
	int	neg;

	neg = 1;
	result = 0;
	while (*str == '\v' || *str == '\f' || *str == '\r' || *str == '\t'
			|| *str == '\n' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (long)INT32_MAX + 1 && neg == -1)
			return (0);
		if (result > (long)INT32_MAX && neg == 1)
			return (-1);
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (result);
}
