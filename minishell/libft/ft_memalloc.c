/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:17:28 by erwepifa          #+#    #+#             */
/*   Updated: 2018/11/27 14:54:27 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (size == 0)
		return (NULL);
	tmp = NULL;
	if (!(tmp = (void *)malloc(size)))
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
