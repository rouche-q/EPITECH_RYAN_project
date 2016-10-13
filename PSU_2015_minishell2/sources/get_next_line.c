/*
** get_next_line.c for base in /home/rouche-q/utiles/sources
** 
** Made by Rouche-q
** Login   <rouche-q@epitech.net>
** 
** Started on  Mon May  2 17:58:42 2016 Rouche-q
** Last update Mon May  2 17:59:45 2016 Rouche-q
*/

#include "base.h"

char		*my_realloc(char *str, int size)
{
  int		i;
  char		*tmp;

  i = 0;
  if ((tmp = malloc((my_strlen(str) + size + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  free(str);
  tmp[i] = '\0';
  return (tmp);
}


char		*get_next_line(int fd)
{
  static char	buf[READ_SIZE];
  char		*ret;
  static int	rd = 0;
  static int	i = 0;
  int		j;

  if ((j = 0) && fd < 0)
    return (NULL);
  if (i == 0)
    rd = read(fd, buf, READ_SIZE);
  if (rd <= 0 || ((ret = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL))
    return (NULL);
  while ((ret[j++] = buf[i++]) != '\n' && i <= rd);
  ret[--j] = '\0';
  if (buf[i - 1] == '\n')
    return (ret);
  while ((rd = read(fd, buf, READ_SIZE)) > 0)
    {
      i = (ret = my_realloc(ret, READ_SIZE))[0] * 0;
      while ((ret[j++] = buf[i++]) != '\n' && i <= rd);
      ret[--j] = '\0';
      if (buf[i - 1] == '\n')
	return (ret);
    }
  return (ret);
}
