/*
** my_strcompar.c for base in /home/rouche-q/utiles/sources
** 
** Made by Rouche-q
** Login   <rouche-q@epitech.net>
** 
** Started on  Mon May  2 18:00:28 2016 Rouche-q
** Last update Mon May  2 18:00:32 2016 Rouche-q
*/

#include "base.h"

int		my_strcompar(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (-1);
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
  	return (-1);
      i++;
    }
  return (0);
}
