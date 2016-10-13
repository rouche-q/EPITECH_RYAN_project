Started/*
** Q_ROUGEsh.h for Q_ROUGEsh in /home/rouche-q/rendu/PSU/PSU_2015_minishell2/minishell1
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Sun Mar 20 06:13:37 2016 Rouche-q
** Last update Tue Jul  5 16:25:25 2016 Rouche-q
*/

#ifndef Q_ROUGESH_H_
# define Q_ROUGESH_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "base.h"

typedef struct	s_env
{
  char		*var;
  char		*info;
  struct s_env	*next;
  struct s_env	*prev;
}		t_env;

t_env		*get_env_list(char **env);
t_env		*create_list();
t_env		*file_list(char *env, t_env *list_env);
void		getcmd(char *cmd, t_env *env_list);
void		free_tab(char **tab);
void		free_env(t_env *list);
void		my_exit(char **tab, t_env *list);
void		env_sh(char **tab, t_env *env_list);
void		my_execve(char **cmd_tab, t_env *env_list);
char		**file_tab(char	**tab, t_env *tmp);
void		triple_free(char **cmd_tab, char **tab_path, char **tab_env);
char		*get_access(char *cmd, char **tab_path);
void		triple_free(char **cmd_tab, char **tab_path, char **tab_env);
void		unsetenv_sh(char **tab, t_env *env_list);
void		setenv_sh(char **tab, t_env *env_list);
int		my_strlentab(char **tab);
void		my_cd(char	**tab_cmd, t_env *env_list);
void		multi_cmd(char *cmd, t_env *env);

#endif /* !Q_ROUGESH_H_ */
