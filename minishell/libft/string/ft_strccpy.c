/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 12:13:37 by erwepifa          #+#    #+#             */
/*   Updated: 2019/06/24 12:13:46 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strccpy(const char *s, int c)
{
	int		i;
	char	*str;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i] && s[i] != c)
		;
	!(str = (char*)malloc(sizeof(char) * i + 1)) ? exit(EXIT_FAILURE) : 0;
	str[i] = 0;
	while (i--)
		str[i] = s[i];
	return (str);
}
