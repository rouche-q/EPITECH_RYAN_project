/*
** main.C for main in /home/rouche-q/rendu/PSU/PSU_2015_minishell2/minishell1
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Sun Mar 20 05:55:12 2016 Rouche-q
** Last update Wed May 18 19:25:39 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

void		test_env(char **env)
{
  if (env[0] == NULL)
    {
      my_putstr("Don't mess with me, you use env -i before launch me\n");
      exit(0);
    }
}

int		main(int argc, char **argv, char **env)
{
  t_env		*env_list;
  char		*cmd;

  if (argc > 1 && argv[0] != NULL)
    return (0);
  test_env(env);
  env_list = get_env_list(env);
  while (1)
    {
      my_putstr("Q_ROUCHE-SH $> ");
      cmd = get_next_line(0);
      getcmd(cmd, env_list);
      free(cmd);
    }
  return (0);
}
