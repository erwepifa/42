/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thescriv <thescriv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:49:42 by thescriv          #+#    #+#             */
/*   Updated: 2019/05/28 11:13:56 by tescriva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && --n >= 1)
		i++;
	return (s1[i] != s2[i] ? (unsigned char)s1[i] - (unsigned char)s2[i] : 0);
}
