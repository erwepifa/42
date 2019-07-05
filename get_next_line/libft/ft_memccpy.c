/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:04:36 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/23 12:21:19 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int		i;
	unsigned char		d;
	unsigned char		*dest1;
	unsigned const char	*src1;

	i = 0;
	d = (unsigned char)c;
	dest1 = (unsigned char *)dest;
	src1 = (unsigned const char *)src;
	while (i < n)
	{
		if ((*dest1++ = *src1++) == d)
			return (dest1);
		i++;
	}
	return (NULL);
}
