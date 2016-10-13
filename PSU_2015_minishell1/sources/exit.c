/*
** exit.c for exit in /home/rouche-q/rendu/PSU/PSU_2015_minishell2/minishell1
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Thu Mar 31 14:56:04 2016 Rouche-q
** Last update Wed May 18 22:50:25 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

void		triple_free(char **cmd_tab, char **tab_path, char **tab_env)
{
  free_tab(cmd_tab);
  free_tab(tab_path);
  free_tab(tab_env);
}

void		free_env(t_env *list)
{
  t_env		*tmp;
  t_env		*next;

  tmp = list;
  while (tmp->next != NULL)
    {
      next = tmp->next;
      free(tmp->var);
      free(tmp->info);
      free(tmp);
      tmp = next;
    }
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
}

void		my_exit(t_env *list, char **tab)
{
  free_env(list);
  free_tab(tab);
  my_putstr("Thank you for having used the Q_ROUGEsh\n");
  exit(1);
}
