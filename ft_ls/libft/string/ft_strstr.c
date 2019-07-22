/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:54:32 by thescriv          #+#    #+#             */
/*   Updated: 2019/05/28 11:14:11 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (needle[k])
		k++;
	if (k == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[j] == haystack[i + j])
		{
			if (!needle[j + 1])
				return ((char *)&haystack[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
