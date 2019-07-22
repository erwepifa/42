/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:41:31 by thescriv          #+#    #+#             */
/*   Updated: 2019/05/31 11:59:16 by thescriv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_itoa(intmax_t n)
{
	char		*s;
	int			i;
	intmax_t	j;

	if (n == 0 || n == 1 || !n)
	{
		s = (char*)malloc(sizeof(char) * 2);
		s[0] = n == 1 ? '1' : '0';
		s[1] = '\0';
		return (s);
	}
	j = (intmax_t)n;
	n < 0 ? j *= -1 : 0;
	i = ft_intlen(j);
	s = (char*)malloc(sizeof(*s) * i + 2);
	if (!s)
		return (NULL);
	s[i] = '\0';
	while (j > 0)
	{
		s[--i] = (j % 10) + '0';
		j /= 10;
	}
	return (s);
}

char	*pf_itoa_base(uintmax_t n, char *b, int base)
{
	char		*s;
	int			i;

	if (n == 0 || !n)
	{
		s = (char*)malloc(sizeof(char) * 2);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	i = ft_intlen_unsigned(n, base);
	s = (char*)malloc(sizeof(char) * i);
	if (!s)
		return (NULL);
	s[i] = '\0';
	while (n != 0)
	{
		s[--i] = b[n % base];
		n /= base;
	}
	return (s);
}
