/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:45:20 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/10 23:07:11 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    cmd_echo(char **tab)
{
    int i;

    i = 0;
    while (tab[++i])
    {
        ft_putstr(tab[i]);
        if (tab[i + 1])
            ft_putchar(' ');
        else if (!tab[i + 1])
            ft_putchar('\n');
    }
}
