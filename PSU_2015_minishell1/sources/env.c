/*
** env.c for env in /home/rouche-q/rendu/project_RYAN/PSU_2015_minishell1/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Thu May 12 11:26:53 2016 Rouche-q
** Last update Thu May 12 11:27:39 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

void		env_sh(t_env *env_list)
{
  t_env		*aff;

  aff = env_list;
  aff = aff->next;
  while (aff->next != NULL)
    {
      my_putstr(aff->var);
      my_putchar('=');
      my_putstr(aff->info);
      my_putchar('\n');
      aff = aff->next;
    }
}

