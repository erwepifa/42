/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:53:17 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/22 22:56:42 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check(char **s, char **line, int fd)
{
	if (s[fd][0] == '\0' || s[fd] == NULL)
		return (0);
	else
	{
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = ft_strnew(1);
		return (1);
	}
}

int		ft_check_v2(char **s, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmp = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = tmp;
		return (1);
	}
	else if (s[fd][i] == '\0')
		return (ft_check(s, line, fd));
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				ret;
	static	char	*s[OPEN_MAX];

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || fd > OPEN_MAX)
		return (-1);
	if (BUFF_SIZE < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
		{
			if (!(s[fd] = ft_strnew(1)))
				return (0);
		}
		str = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = str;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (ft_check_v2(s, line, fd));
}
