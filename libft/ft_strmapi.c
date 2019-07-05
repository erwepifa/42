/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:05:48 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/26 14:06:13 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = -1;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(result = ft_strnew(ft_strlen(s))))
		return (NULL);
	ft_strcpy(result, s);
	while (result[++i])
		result[i] = (*f)(i, result[i]);
	return (result);
}
