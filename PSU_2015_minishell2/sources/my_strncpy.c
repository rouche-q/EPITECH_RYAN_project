/*
** my_strncpy.c for base in /home/rouche-q/utiles/sources
** 
** Made by Rouche-q
** Login   <rouche-q@epitech.net>
** 
** Started on  Mon May  2 18:03:09 2016 Rouche-q
** Last update Mon May  2 18:03:11 2016 Rouche-q
*/

#include "base.h"

char		*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  while (i <= n)
    {
      dest[i] = '\0';
      i++;
    }
  return (dest);
}
