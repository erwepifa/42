/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:07:35 by thescriv          #+#    #+#             */
/*   Updated: 2019/05/27 20:21:15 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(intmax_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_intlen_unsigned(uintmax_t n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

int		ft_strwlen(wchar_t *str, t_arg *pf)
{
	int i;
	int n;
	int j;
	int width;

	i = 0;
	n = 0;
	width = pf->wipr != -1 ? pf->wipr : -1;
	while (str[i] != '\0')
	{
		j = ft_charlen(str[i]);
		if (j == -1 || (j > MB_CUR_MAX && width < 0))
			return (-1);
		else if (width > 0 && j > width)
			return (n);
		width -= j;
		n += j;
		i++;
	}
	return (n);
}

int		ft_charlen(wchar_t c)
{
	if ((0xD800 <= c && c <= 0xDFFF) || c < 0 || c > 0x10FFFF)
		return (-1);
	if (c > 0xFFFF)
		return (4);
	else if (c > 0x7FF)
		return (3);
	else if ((c > 0x7F && MB_CUR_MAX >= 2) || c > 0xFF)
		return (2);
	else
		return (1);
}
