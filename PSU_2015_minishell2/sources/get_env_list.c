/*
** get_env_list.c for get_env_list in /home/rouche-q/rendu/PSU/PSU_2015_minishell2/minishell1
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Sun Mar 20 09:59:33 2016 Rouche-q
** Last update Thu Apr 14 15:40:26 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"


t_env		*create_list()
{
  t_env		*list;

  if ((list = malloc(sizeof (t_env))) == NULL)
    return (NULL);
  list->var = NULL;
  list->info = NULL;
  list->next = NULL;
  list->prev = NULL;
  return (list);
}

t_env		*get_env_list(char **env)
{
  t_env		*list_env;
  int		i;

  i = 0;
  list_env = create_list();
  while (env[i] != NULL)
    {
      list_env = file_list(env[i], list_env); 
      i++;
    }
  return (list_env);
}

t_env		*file_list(char *env, t_env *list_env)
{
  t_env		*tmp;
  t_env		*new;
  
  tmp = list_env;
  new = create_list();
  while (tmp->next != NULL)
    tmp = tmp->next;
  if ((new->var = malloc((my_strlentochar(env, '=') + 1) * 
			 sizeof (char))) == NULL)
    return (NULL);
  if ((new->info = malloc((my_strlen(env) - my_strlentochar(env, '=') + 1) * 
			  sizeof (char))) == NULL)
    return (NULL);
  new->var = my_strncpy(new->var, env, my_strlentochar(env, '='));
  new->info = my_strcpy(new->info, env + my_strlentochar(env, '=') + 1);
  new->next = NULL;
  tmp->next = new;
  new->prev = tmp;
  return (list_env);
}
