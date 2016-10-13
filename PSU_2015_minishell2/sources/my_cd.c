/*
** my_cd.c for my_cd in /home/rouche-q/rendu/project_RYAN/PSU_2015_minishell2/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Wed Jun  8 10:56:58 2016 Rouche-q
** Last update Wed Jun  8 19:30:27 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

void		basic(char *tab)
{
  if (access(tab, F_OK | R_OK) != 0)
    {
      my_putstr(tab);
      my_putstr(" :folder doesn't exist or you don't have the right to access");
      my_putchar('\n');
      return;
    }
  if (chdir(tab) == -1)
    {
      my_putstr(tab);
      my_putstr(" :folder doesn't exist or you don't have the right to access");
      my_putchar('\n');
      return; 
    } 
}

void		go_home(t_env *env)
{
  t_env		*tmp;

  tmp = env;
  while (my_strcompar(tmp->var, "HOME") == -1)
    tmp = tmp->next;
  basic(tmp->info);
}

void		my_cd(char **tab, t_env *env_list)
{
  if (my_strlentab(tab) == 1)
    go_home(env_list);
  else if (my_strlentab(tab) == 2)
    basic(tab[1]);
  else
    {
      my_putstr("cd : Usage : cd [DIRECTORY]\n");
      return;
    }    
}
