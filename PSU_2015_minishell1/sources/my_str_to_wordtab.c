/*
** my_str_to_wordtab.c for base in /home/rouche-q/utiles/sources
** 
** Made by Rouche-q
** Login   <rouche-q@epitech.net>
** 
** Started on  Mon May  2 18:04:05 2016 Rouche-q
** Last update Wed May 18 19:22:36 2016 Rouche-q
*/

#include "base.h"

int		count_char(char *str, char limit)
{
  int		i;

  i = 0;
  while (str[i] != limit && str[i] != '\0')
    i++;
  return (i);
}

int		count_words(char *str, char limit)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == limit || str[i + 1] == '\0')
	{
	  while (str[i] == limit)
	    i++;
	  nb++;
	}
      i++;
    }
  return (nb);
}

char	**my_str_to_wordtab(char *str, char limit)
{
  char	**tab;
  int	i;
  int	j;
  int	wd;

  i = 0;
  wd = count_words(str, limit);
  if ((tab = malloc(sizeof(char *) * (wd + 1))) == NULL)
    return (NULL);
  while (i < wd)
    {
      j = 0;
      if ((tab[i] = malloc(count_char(str, limit) + 1)) == NULL)
	return (NULL);
      while (str[j] != limit && str[j] != '\0')
	{
	  tab[i][j] = str[j];
	  j++;
	}
      tab[i][j] = '\0';
      while (*str++ != limit && *str != '\0');
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
