/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:26:08 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/10 20:28:28 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		i;
	int		o;
	char	*p;

	o = 0;
	i = 0;
	if (!(s1) || (!(s2)))
		return (NULL);
	while (s1[i])
		i++;
	while (s2[o])
		o++;
	if (!(p = (char*)malloc(sizeof(*p) * (i + o) + 1)))
		return (NULL);
	i = 0;
	o = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[o])
		p[i++] = s2[o++];
	p[i] = '\0';
	return (p);
}
