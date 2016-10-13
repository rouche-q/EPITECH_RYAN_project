/*
** fctbase.c for base in /home/rouche-q/utiles/sources
** 
** Made by Rouche-q
** Login   <rouche-q@epitech.net>
** 
** Started on  Mon May  2 17:58:15 2016 Rouche-q
** Last update Mon May  2 17:58:19 2016 Rouche-q
*/

#include "base.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	my_strlentochar(char *str, char c)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
