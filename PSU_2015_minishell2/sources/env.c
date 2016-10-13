/*
** env.c for env in /home/rouche-q/rendu/project_RYAN/PSU_2015_minishell1/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Thu May 12 11:26:53 2016 Rouche-q
** Last update Tue Jun  7 13:34:29 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

int		my_strlentab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void		unsetenv_sh(char **tab, t_env *env_list)
{
  t_env		*tmp;
  
  tmp = env_list;
  if (my_strlentab(tab) != 2)
    my_putstr("Usage : unsetenv [VARIABLE]\n");
  else
    {
      while (my_strcompar(tmp->var, tab[1]) == -1 && tmp->next != NULL)
	tmp = tmp->next;
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
      free(tmp->var);
      free(tmp->info);
      free(tmp);
    }
  free_tab(tab);
}

t_env		*new_var(char **tab)
{
  t_env		*new;

  new = create_list();
  if ((new->var = malloc(sizeof(char) * (my_strlen(tab[1]) + 1))) == NULL)
    return (NULL);
  
  new->var = my_strcpy(new->var, tab[1]);
  my_putstr(tab[1]);
  if (tab[2] == NULL || (new->info = malloc(my_strlen(tab[2]) + 1)) == NULL)
    return (NULL);
  my_putstr(tab[2]);
  new->info = my_strcpy(new->info, tab[2]);
  new->prev = NULL;
  new->next = NULL;
  return (new);
}

void		setenv_sh(char **tab, t_env *env_list)
{
  t_env		*new;
  t_env		*tmp;

  tmp = env_list;
  if (my_strlentab(tab) < 2 || my_strlentab(tab) > 3)
    my_putstr("Usage : setenv [VARIABLE] [OPTION]\n");
  else
    {
      while (my_strcompar(tmp->var, tab[1]) == -1 && tmp->next != NULL)
	tmp = tmp->next;
      if (my_strcompar(tmp->var, tab[1]) == 0)
	{
	  free(tmp->info);
	  if (tab[2] == NULL || (tmp->info = malloc(my_strlen(tab[2]) + 1)) == NULL)
	    return ;
	  my_strcpy(tmp->info, tab[2]);
	}
      else 
	{
	  if ((new = new_var(tab)) == NULL)
	    return;
	  new->prev = tmp;
	  tmp->next = new;
	}
      free_tab(tab);
    }
}

void		env_sh(char **tab, t_env *env_list)
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
  free_tab(tab);
}

