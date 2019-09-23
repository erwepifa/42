/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:54:24 by erwepifa          #+#    #+#             */
/*   Updated: 2019/09/11 12:04:26 by erwepifa         ###   ########.fr       */
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

int		ft_error(char *s1, char *name);
char	*ft_souder(char *s1, char *s2, char *s3);
char	**set_env(char **tab, char **env);
char	**unset_env(char **tab, char **env);
char	**check_path(char **env);
int		check_tab(char **tab);
int		run_cmd(char *name, char **env, char **tab);
char	**malloc_setenv(char **env, char *tab);
char	**malloc_unsetenv(char **env, int value);
char	*ft_suppr_tab(char *line);
int		ft_find_material(char *str);
char	**env_builtin(char **env, char **tab);
char	**check_builtin(char *line, char **env, char **tab);
void	print_env(char **tab);
void	print_minishell(char **env);
char	*get_user(char **env);
char	*get_pwd(char **env);
void	write_prompt(char **env);
void	cmd_echo(char **tab);
char	*access_dir(char *str);
int		search_exec(char *cmd, char *tab);
char	*parsing_cmd(char **cmd, char **tab);
char	**cmd_cd(char **env);
int		access_cd(char *str, char **tab);
char	**run_cd(char *str, char **env, char **tab);
char	**free_all_tab(char **av);
int		access_exec(char *cmd, char *tab);
char	**check_pwd_for_cd(char **env);
char	**check_oldpwd_for_cd(char **env);
char	**get_oldpwd(char **env, char *str);
char	**check_cd_home(char **env);
char	**exec_final(char **cmd, char **env, char **tab);

#endif
