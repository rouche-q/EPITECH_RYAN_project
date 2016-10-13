/*
** my_execve2.c for my_execve2 in /home/rouche-q/rendu/project_RYAN/PSU_2015_minishell2
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Fri Jun  3 11:24:37 2016 Rouche-q
** Last update Tue Jul  5 16:26:49 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

char		*get_access(char *cmd, char **tab_path)
{
  int		i;
  char		*exec;

  i = 0;
  if (access(cmd, F_OK | X_OK) == 0)
    return (cmd);
  while (tab_path[i] != NULL)
    {
      exec = my_strconcat(tab_path[i], "/");
      exec = my_strconcat(exec, cmd);
      if (access(exec, F_OK | X_OK) == 0)
	return (exec);
      free(exec);
      i++;
    }
  my_putstr(cmd);
  my_putstr(" : command not found\n");
  free(cmd);
  return (NULL);
}
