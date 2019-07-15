/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:25:07 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/15 21:26:26 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_sous_d_ex(char *s2, t_flag m)
{
	while (m.new[m.i] == '/')
		m.i--;
	m.i = m.i + 2;
	while (s2[m.o])
		m.new[m.i++] = s2[m.o++];
	m.new[m.i] = '\0';
	return (m.new);
}

char		*ft_sous_d(char *s1, char *s2)
{
	t_flag m;

	m.c = NULL;
	m.new = NULL;
	m.i = 0;
	m.o = 0;
	if (ft_strcmp(s1, ".") == 0)
		return (ft_strdup(s2));
	if (!(m.new = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	ft_strcpy(m.new, s1);
	while (m.new[m.i])
		m.i++;
	m.i--;
	if (m.new[m.i] == '/')
		return (ft_sous_d_ex(s2, m));
	m.new[++m.i] = '/';
	m.i++;
	while (s2[m.o])
		m.new[m.i++] = s2[m.o++];
	m.new[m.i] = '\0';
	return (m.new);
}
