/*
** getcmd.c for getcmd in /home/rouche-q/rendu/project_RYAN/PSU_2015_minishell1/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Thu May 12 10:53:23 2016 Rouche-q
** Last update Wed Jun  8 12:11:27 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

void		(*ptr_fct[6])(char **tab_cmd, t_env *env_list) =
{
  &my_exit, &env_sh, &unsetenv_sh, &setenv_sh, &my_cd, &my_execve
};

char		**init_b()
{
  char		**tab;
  int		i;

  i = 0;
  if ((tab = malloc(sizeof (char *) * 6)) == NULL)
    return (NULL);
  while (i < 6)
    {
      if ((tab[i] = malloc(sizeof (char) * 10)) == NULL)
	return (NULL);
      i++;
    }
  tab[0] = my_strcpy(tab[0], "exit");
  tab[1] = my_strcpy(tab[1], "env");
  tab[2] = my_strcpy(tab[2], "unsetenv");
  tab[3] = my_strcpy(tab[3], "setenv");
  tab[4] = my_strcpy(tab[4], "cd");
  tab[5] = NULL;
  return (tab);
}

void		getcmd(char *cmd, t_env *env_list)
{
  char		**tab_cmd;
  int		i;
  char		**tab_b;

  i = 0;
  env_list = env_list;
  tab_cmd = my_str_to_wordtab(cmd, ' ');
  free(cmd);
  tab_b = init_b();
  while (i < 5 && my_strcompar(tab_b[i], tab_cmd[0]) == -1)
      i++;
  free_tab(tab_b);
  (*ptr_fct[i])(tab_cmd, env_list);
}
