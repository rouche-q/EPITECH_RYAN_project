/*
** direction.c for direction in /home/rouche-q/rendu/project_RYAN/Snake_Ryan/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Mon May  9 09:58:28 2016 Rouche-q
** Last update Wed May 11 18:21:49 2016 Rouche-q
*/

#include "snake.h"

t_body		*go_up(t_body *head, t_snake snake, int c)
{
  if (head->x <= 0 || head == NULL)
    return (head);
  if (c == KEY_UP)
    head = tail_to_head(head, head->x, head->y - 1, snake);
  return (head);
}

t_body		*go_down(t_body *head, t_snake snake, int c)
{
  if (head->x >= snake.x || head == NULL)
    return (head);
  if (c == KEY_DOWN)
    head = tail_to_head(head, head->x, head->y + 1, snake);
  return (head);
}

t_body		*go_left(t_body *head, t_snake snake, int c)
{
  if (head->y <= 0 || head == NULL)
    return (head);
  if (c == KEY_LEFT)
    head = tail_to_head(head, head->x - 1, head->y, snake);
  return (head);
}

t_body		*go_right(t_body *head, t_snake snake, int c)
{
  if (head->y >= snake.y || head == NULL)
    return (head);
  if (c == KEY_RIGHT)
    head = tail_to_head(head, head->x + 1, head->y, snake);
  return (head);
}

t_body		*direction(t_body *head, t_snake snake, t_score score ,int c)
{
 
  head = go_up(head, snake, c);
  head = go_down(head, snake, c);
  head = go_left(head, snake, c);
  head = go_right(head, snake, c);
  if (head->x == score.a_posx && head->y == score.a_posy)
    head = add_body(head, score);
  return (head);
}
