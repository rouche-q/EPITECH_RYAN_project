/*
** main.C for main in /home/rouche-q/rendu/PSU/PSU_2015_minishell2/minishell1
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Sun Mar 20 05:55:12 2016 Rouche-q
** Last update Wed Jun  8 17:35:38 2016 Rouche-q
*/

#include "Q_ROUGEsh.h"

void		test_env(char **env)
{
  if (env[0] == NULL)
    {
      my_putstr("Don't mess with me, you use env -i before launch me");
      exit(0);
    }
}

void		mabite(int sig)
{
  if (sig == 2)
    {
      my_putstr("\b\b  \n");
      my_putstr("Q_ROUCHE-SH $> ");
    }
  signal(SIGINT, mabite);
}

int		main(int argc, char **argv, char **env)
{
  t_env		*env_list;
  char		*cmd;

  if (argc != 1 && argv[0] != NULL)
    return (0);
  test_env(env); 
  env_list = get_env_list(env);
  env_list = env_list;
  signal(SIGINT, mabite);
  my_putstr("Q_ROUCHE-SH $> ");
  while ((cmd = get_next_line(0)) != NULL)
    {
      if (my_strlen(cmd) > 0)
	multi_cmd(cmd, env_list);
      my_putstr("Q_ROUCHE-SH $> ");
    }
  return (0);
}
