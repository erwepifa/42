/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:30:02 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/23 15:36:59 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	j = ft_strlen(to_find);
	while (*str != '\0' && len)
	{
		if (j > len)
			return (NULL);
		if (ft_strncmp(str, to_find, j) == 0)
			return ((char *)str);
		len--;
		str++;
	}
	return (NULL);
}
