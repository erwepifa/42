/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:54:24 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/10 23:26:28 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>
# include "libft/libft.h"

/* env.c */
char	*ft_souder(char *s1, char *s2, char *s3);
char    **set_env(char **tab, char **env);
char 	**unset_env(char **tab, char **env);

/* execute.c */

char    **check_path(char **env);
int     check_tab(char **tab);
int     run_cmd(char *name, char **env, char **tab);


/* malloc.c */
char    **malloc_setenv(char **env, char *tab);
char    **malloc_unsetenv(char **env, int value);

/* options.c */
char	*ft_suppr_tab(char *line);
int		ft_find_material(char *str);
char    **env_builtin(char **env, char **tab);
char    **check_builtin(char *line, char **env, char **tab);

/* minishell.c */
void    print_env(char **tab);
void    print_minishell(char **env);
char    *get_user(char **env);
char    *get_pwd(char **env);
void    write_prompt(char **env);

/* echo.c */
void    cmd_echo(char **tab);

/* access.c */

char    *access_dir(char *str);

#endif
