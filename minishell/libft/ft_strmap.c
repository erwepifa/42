/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:20:27 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/26 15:07:24 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*result;

	i = -1;
	result = NULL;
	if (!s || !f)
		return (NULL);
	if (!(result = ft_strnew(ft_strlen(s))))
		return (NULL);
	ft_strcpy(result, s);
	while (result[++i])
		result[i] = (*f)(result[i]);
	result[i] = '\0';
	return (result);
}
