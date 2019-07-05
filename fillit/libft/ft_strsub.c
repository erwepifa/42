/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:39:39 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/26 14:24:04 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = ft_strnew(len);
	if (!s || !str)
		return (NULL);
	while (i < len)
	{
		if (!s[i + start])
			return (NULL);
		str[i] = s[i + start];
		i++;
	}
	return (str);
}
