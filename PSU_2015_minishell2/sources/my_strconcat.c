/*
** my_strconcat.c for base in /home/rouche-q/utiles/sources
** 
** Made by Rouche-q
** Login   <rouche-q@epitech.net>
** 
** Started on  Mon May  2 18:01:05 2016 Rouche-q
** Last update Mon May  2 18:01:08 2016 Rouche-q
*/

#include "base.h"

char		*my_strconcat(char *s1, char *s2)
{
  int   z;
  char  *s3;

  z = 0;
  if (s2 == NULL)
    return (s1);
  if (s1 == NULL)
    return (s2);
  if ((s3 = malloc((my_strlen(s1) + my_strlen(s2) + 1) *
		   sizeof(char *))) == NULL)
    return (NULL);
  while (z <= my_strlen(s1))
    {
      s3[z] = s1[z];
      z++;
    }
  z = 0;
  while (z <= my_strlen(s2))
    {
      s3[z + my_strlen(s1)] = s2[z];
      z++;
    }
  s3[my_strlen(s1) + my_strlen(s2) + 1] = '\0';
  return (s3);
}
