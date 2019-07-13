/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:35:05 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/13 23:21:03 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char		**free_all_tab(char **av)
{
	int i;

	i = 0;
	if (!av)
		return (NULL);
	while (av[i])
		ft_strdel(&av[i++]);
	free(av);
	av = NULL;
	return (av);
}
