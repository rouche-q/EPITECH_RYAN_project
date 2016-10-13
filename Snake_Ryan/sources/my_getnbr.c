/*
** my_getnbr.c for my_getnbr in /home/rouche_q/rendu/PSU_2015_my_printf_bootstrap
** 
** Made by quentin rouchet
** Login   <rouche_q@epitech.net>
** 
** Started on  Fri Nov  6 18:32:12 2015 quentin rouchet
** Last update Thu May  5 11:43:56 2016 Rouche-q
*/

#include "base.h"

int     only_nbr(char *str)
{
  int   i;

  i = 0;
  while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
    {
      if ((str[i] == '-' || str[i] == '+')
          && i != 0 && str[i - 1] >= '0' && str[i] <= '9')
        {
          return (i);
        }
      i++;
    }
  return (i);
}

int     my_getnbr(char *a)
{
  int   result;
  int   n;
  int   m;
  int   o;

  result = 0;
  o = 0;
  m = 1;
  n = only_nbr(a) - 1;
  while (o == '-' || o == '=')
    {
      a[o] = '\0';
    }
  while (n >= 0 && a[n] != '-' && a[n] != '+')
    {
      result = result + ((a[n] - 48) * m);
      n = n - 1;
      m = m * 10;
    }
  return (result);
}
