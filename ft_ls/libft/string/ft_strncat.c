/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:40:16 by thescriv          #+#    #+#             */
/*   Updated: 2019/05/28 11:13:54 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (s1[i])
		i++;
	while (s2[++j] && n--)
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return (s1);
}
