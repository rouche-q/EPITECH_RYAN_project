/*
** read.c for read in /home/rouche-q/rendu/PSU/PSU_2015_minishell2/minishell1
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Sun Mar 20 08:12:28 2016 Rouche-q
** Last update Wed May 18 19:23:02 2016 Rouche-q
*/

char		*read_standar()
{
  char		*cmd;
  char		c;
  int		i;

  i = 0;
  if ((cmd = malloc(sizeof (char) * 2)) == NULL)
    return (NULL);
  cmd[i] = '\0';
  while (read(0, &c, 1) > 0)
    {
      if (c == '\n')
	return (cmd);
      cmd[i++] = c;
      cmd[i] = '\0';
      cmd = my_realloc(cmd, 2);
    }
  return (cmd);
}
