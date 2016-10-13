/*
** my_execve.c for my_execve in /home/rouche-q/rendu/project_RYAN/PSU_2015_minishell1/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Thu May 12 14:27:46 2016 Rouche-q
** Last update Sun Jun  5 18:06:49 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

char		**list_to_char(t_env *list)
{
  int		i;
  char		**env_tab;
  t_env		*tmp;

  i = 0;
  tmp = list->next;
  while (tmp->next != NULL && (i++) + 1)
      tmp = tmp->next;
  if ((env_tab = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  tmp = list->next;
  while (tmp->next != NULL)
    {
      if ((env_tab[i] = malloc(my_strlen(tmp->var)
			       + my_strlen(tmp->info) + 2)) == NULL)
       return (NULL);
      tmp = tmp->next;
      i++;
    }
  tmp = list->next;
  env_tab = file_tab(env_tab, tmp);
  return (env_tab);
}

char		**file_tab(char	**tab, t_env *tmp)
{
  int		i;

  i = 0;
  while (tmp->next != NULL)
    {
      tab[i] = my_strcpy(tab[i], tmp->var);
      tab[i] = my_strconcat(tab[i], "=");
      tab[i] = my_strconcat(tab[i], tmp->info);
      i++;
      tmp = tmp->next;
    }
  tab[i] = NULL;
  return (tab);
}

char		**path_to_tab(t_env *list)
{
  t_env		*tmp;
  char		**tab;

  tmp = list->next;
  while (tmp->next != NULL)
    {
      if (my_strcompar("PATH", tmp->var) == 0)
	{
	  tab = my_str_to_wordtab(tmp->info, ':');
	  return (tab);
	}
      else
	tmp = tmp->next;
    }
  my_putstr("No path variable\n");
  return (NULL);
}

int		do_that(char **cmd_tab, char **tab_env, char **tab_path)
{
  int		pid;
  int		status;
  char		*exec;

  pid = fork();
  if (pid == -1)
    {
      my_putstr("Bad fork");
      return (-1);
    }
  else if (pid == 0)
    {
      if ((exec = get_access(cmd_tab[0], tab_path)) == NULL || execve(exec, cmd_tab, tab_env) == -1)
	{
	  triple_free(cmd_tab, tab_path, tab_env);
	  exit(0);
	}
    }
  else
    wait(&status);
 triple_free(cmd_tab, tab_path, tab_env);
 return (0);
}

void		my_execve(char **cmd_tab, t_env *env_list)
{
  char		**tab_env;
  char		**tab_path;
  
  tab_env = list_to_char(env_list);
  if ((tab_path = path_to_tab(env_list)) == NULL)
    return;
  do_that( cmd_tab, tab_env, tab_path);
  return; 
}
