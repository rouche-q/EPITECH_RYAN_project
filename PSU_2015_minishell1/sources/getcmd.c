/*
** getcmd.c for getcmd in /home/rouche-q/rendu/project_RYAN/PSU_2015_minishell1/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Thu May 12 10:53:23 2016 Rouche-q
** Last update Wed May 18 23:00:54 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

void		getcmd(char *cmd, t_env *env_list)
{
  char		**tab_cmd;

  tab_cmd = my_str_to_wordtab(cmd, ' ');
  if (my_strcompar("exit", tab_cmd[0]) == 0)
    my_exit(env_list, tab_cmd);
  else if (my_strcompar("env", tab_cmd[0]) == 0)
    env_sh(env_list);
  else if (cmd[0] != '\n')
    my_execve(tab_cmd, env_list);
}
