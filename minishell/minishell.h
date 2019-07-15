/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:54:24 by erwepifa          #+#    #+#             */
/*   Updated: 2019/07/15 21:26:20 by erwepifa         ###   ########.fr       */
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


char	*ft_strjoin2(char const *s1, char const *s2);

char		*ft_sous_d_ex(char *s2, t_flag m);
char		*ft_sous_d(char *s1, char *s2);
int		ft_error(char *s1, char *name);
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
int     search_exec(char *cmd, char *tab);
char    *parsing_cmd(char   **cmd, char **tab);



char    **cmd_cd(char **env);
int     access_cd(char *str, char **tab);
char    **run_cd(char *str, char **env, char **tab);


/* free_tab */

char		**free_all_tab(char **av);
int     access_exec(char *cmd, char *tab);

/* a trier */
char    **check_pwd_for_cd(char **env);
char    **check_oldpwd_for_cd(char **env);
char    **get_oldpwd(char **env, char *str);
char    **check_cd_home(char **env);
char 	**exec_final(char **cmd, char **env, char **tab);

#endif
