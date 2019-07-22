/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescriva <tescriva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:29:19 by tescriva          #+#    #+#             */
/*   Updated: 2019/07/22 21:05:50 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include <dirent.h>
# include <stdlib.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <sys/acl.h>
# include "libft.h"

# define NO_ARG		10
# define WRONG_ARG	11
# define USAGE		12

# define L			0
# define UN			1
# define A			2
# define R			3
# define T			4
# define S			5
# define BIG_R		6
# define D			7
# define F			8

# define RED_L		"\033[1;31m"
# define GREEN_L	"\033[1;32m"
# define GREEN		"\033[0;32m"
# define BLUE		"\033[1;34m"
# define RED		"\033[0;31m"
# define GRAY		"\033[1;30m"
# define GRAY_L		"\033[0;37m"
# define CYAN		"\033[0;36m"
# define CYAN_L		"\033[1;36m"
# define PURPLE		"\033[0;35m"
# define NC			"\033[0m"

# define S_IRWXU    0000700
# define S_IRUSR    0000400
# define S_IWUSR    0000200
# define S_IXUSR    0000100
# define S_IRWXG    0000070
# define S_IRGRP    0000040
# define S_IWGRP    0000020
# define S_IXGRP    0000010
# define S_IRWXO    0000007
# define S_IROTH    0000004
# define S_IWOTH    0000002
# define S_IXOTH    0000001

typedef struct		s_ls
{
	DIR				*path;
	char			*main_path;
	char			*current_path;
	int				total_block;
	int				*size;
	int				recur;
	struct dirent	*dir;
	struct s_lst	*head;
}					t_ls;

typedef struct		s_lst
{
	struct s_info	*val;
	struct s_lst	*next;

}					t_lst;

typedef struct		s_info
{
	char			*path;
	char			*name;
	struct stat		stat;
	char			*pw_name;
	char			*gr_name;
	char			*clock;
}					t_info;

void				error(int err);
int					*ft_get_flag(char *str, int *flag);
void				ft_get_folder(int *flag, t_ls *e, t_lst *lst, char *path);
void				ft_display_ls(t_ls *e, t_lst *lst, int *flag);
t_lst				*create_node(char *name, t_lst *lst, int *flag, t_ls *e,
		t_lst **head);
t_lst				*ft_delete_node(t_lst *lst);
void				ft_sort_node(t_ls *e, t_lst *lst, int *flag);
void				ft_print_info(t_lst *lst, t_ls *e);
void				ft_padding_info(char *tmp, int size);
void				ft_print_data(t_lst *lst);
void				ft_print_symbolic(t_lst *lst);
void				ft_print_perm(t_lst *lst, t_ls *e);
void				ft_print_list(t_lst *lst, t_ls *e, int *flag);
t_lst				*ft_insert_node(t_lst **head, t_lst *lst, t_lst *insert,
		int *flag);
int					*ft_size_zero(int *tab);
DIR					*ft_isdir(char *path);
void				ft_print_color(t_lst *lst);
void				ft_print_perm(t_lst *lst, t_ls *e);
void				get_file_acl(char *path);
#endif
