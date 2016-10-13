/*
** Q_ROUGEsh.h for Q_ROUGEsh in /home/rouche-q/rendu/PSU/PSU_2015_minishell2/minishell1
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Sun Mar 20 06:13:37 2016 Rouche-q
** Last update Wed May 18 22:50:20 2016 Rouche-q
*/

#ifndef Q_ROUGESH_H_
# define Q_ROUGESH_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "base.h"

typedef struct	s_env
{
  char		*var;
  char		*info;
  struct s_env	*next;
  struct s_env	*prev;
}		t_env;

t_env		*create_list();
t_env		*get_env_list(char **env);
t_env		*file_list(char *env, t_env *list_env);
void		getcmd(char *cmd, t_env *env);
void		free_env(t_env *list);
void		free_tab(char **tab);
void		my_exit(t_env *list, char **tab);
void		env_sh(t_env *env_list);
char		**list_to_char(t_env *list);
char		**file_tab(char	**tab, t_env *tmp);
int		my_execve(char **cmd_tab, t_env *env_list);
char		**path_to_tab(t_env *list);
int		do_that(char **cmd_tab, char **tab_env, char *tab_path);
void		triple_free(char **cmd_tab, char **tab_path, char **tab_env);

#endif /* !Q_ROUGESH_H_ */

