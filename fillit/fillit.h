/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:45:17 by erwepifa          #+#    #+#             */
/*   Updated: 2019/01/28 15:44:37 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define OUTERROR 1
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/include/libft.h"
# define BUFF_SIZE 600

typedef struct	s_tetri
{
	int		x;
	int		y;
	int		xsize;
	int		ysize;
	char	lettre;
	char	**bloc;

}				t_tetri;

int				expected_nb_tetri(char *str);
int				check_grid(char *str);
t_tetri			*input_checker(char *file);
void			ft_insertpiece(char **grid, t_tetri piece);
char			*gnl(char *file);
void			ft_updategrid(char **grid, int size, t_tetri *piece, int nbr);
void			ft_removepiece(char **grid, t_tetri *piece, int index, int nbr);
int				ft_pieceislegal(char **grid, t_tetri piece, int size);
void			ft_fillit_res(t_tetri *piece, int nbr);
int				ft_check(char *str, int tetri);
void			ft_error(t_tetri *t, int nb);
void			free_map(char **grid);
void			freepiece(t_tetri *piece, int nb);
int				nb_tetri(char *str);
void			ft_print_tab(char **tab);
int				check_piece(char *str, int i);
int				check_piece2(char *str);
t_tetri			*ft_place(int pc, t_tetri *t, int nb, int k);
t_tetri			*ft_place2(int pc, t_tetri *t, int nb, int k);
t_tetri			*ft_struct_filler(char *str, int nb_tetri);
int				get_width(t_tetri piece);

#endif
