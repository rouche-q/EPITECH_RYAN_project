/*
** colision.c for colision in /home/rouche-q/rendu/project_RYAN/Snake_Ryan/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Wed May 11 14:46:12 2016 Rouche-q
** Last update Wed May 11 17:35:50 2016 Rouche-q
*/

#include "snake.h"

int		c_wall(t_body *head, t_snake snake)
{
  if (head->x <= 0 || head->x >= snake.x)
    return (1);
  else if (head->y <= 0 || head->y >= snake.y)
    return (1);
  return (0);
}

int		c_body(t_body *head)
{
  t_body	*tmp;

  tmp = head;
  while (tmp->next != NULL)
    {
      if (head->x == tmp->x || head->y == tmp->y)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		collision(t_body *head, t_snake snake)
{
  if ((c_wall(head, snake) == 1) || c_body(head) == 1)
    return (1);
  return (0);
}
