/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:41:55 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/23 12:56:37 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nb_word(const char *str, char c)
{
	int		word;

	word = 0;
	if (*str != c && *str)
	{
		str++;
		word++;
	}
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				word++;
		}
		str++;
	}
	return (word);
}

static	int	ft_len(const char *str, char c)
{
	int		count;

	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**dst;

	j = 0;
	i = 0;
	if (!s || (!(dst = (char**)malloc(sizeof(char *) * (nb_word(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(dst[j] = (char *)malloc(sizeof(char) * (ft_len(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				dst[j][i++] = (char)*s++;
			dst[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	dst[j] = NULL;
	return (dst);
}
