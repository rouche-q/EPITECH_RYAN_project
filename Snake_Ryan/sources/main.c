/*
** main.c for main in /home/rouche-q/rendu/project_RYAN/Snake_Ryan
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Thu May  5 10:19:25 2016 Rouche-q
** Last update Wed May 11 18:28:55 2016 Rouche-q
*/

#include "snake.h"

int		init_win(t_snake *snake, int x, int y)
{
  if (x < 10 || x < 10)
    {
      my_putstr("Unplayable field");
      return (-1);
    }
  snake->x = x;
  snake->y = y;
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  t_snake	snake;
  
  if (argc == 3 && init_win(&snake, my_getnbr(argv[1]),
			    my_getnbr(argv[2])) != -1 && *env != NULL)
    play(snake);
  else if (argc == 1 && init_win(&snake, 30, 30) != -1 && *env != NULL)
    play(snake);
  else
    return (0);
  return (0);
}
