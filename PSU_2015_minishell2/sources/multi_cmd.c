/*
** multi_cmd.c for multi_cmd in /home/rouche-q/rendu/project_RYAN/PSU_2015_minishell2/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Wed Jun  8 17:18:32 2016 Rouche-q
** Last update Wed Jun  8 19:57:10 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

char		*epur_str(char *str)
{
  int		i;
  int		j;

  i = -1;
  j = 0;
  while (str[++i] != '\0' && str != NULL)
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  str[j] = str[i];
	  j++;
	  if (str[i + 1] == ' ' || str[i + 1] == '\t')
	    {
	      str[j] = ' ';
	      j++;
	    }
	}
    }
  str[j] = '\0';
  if (str[j - 1] == ' ')
    str[j - 1] = '\0';
  return (str);
}

void		multi_cmd(char *cmd, t_env *env)
{
  char		**tab;
  int		i;

  i = 0;
  cmd = epur_str(cmd);
  tab = my_str_to_wordtab(cmd, ';');
  free(cmd);
  while (tab[i] != NULL)
    {
      getcmd(tab[i], env);
      i++;
    }
}
