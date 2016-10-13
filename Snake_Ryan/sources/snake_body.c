/*
** snake_body.c for snake_body in /home/rouche-q/rendu/project_RYAN/Snake_Ryan
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Fri May  6 09:39:58 2016 Rouche-q
** Last update Wed May 11 12:14:40 2016 Rouche-q
*/

#include "snake.h"

t_body		*init_body(int x, int y)
{
  t_body	*body;

  if ((body = malloc(sizeof(t_body))) == NULL)
    return (NULL);
  body->x = x;
  body->y = y;
  body->next = NULL;
  return (body);
}

t_body		*start_body(t_snake snake)
{
  t_body	*body1;
  t_body	*body2;

  body1 = init_body(snake.x / 2, snake.y / 2);
  body2 = init_body(body1->x + 1, body1->y);
  body1->next = body2;
  return (body1);
}

int		aff_all(t_snake snake, t_body *body, t_score score)
{
  t_body	*tmp;

  if (body == NULL)
    return (0);
  tmp = body;
  while (tmp != NULL)
    {
      mvwprintw(snake.board, tmp->y, tmp->x, "o");
      tmp = tmp->next;
    }
  mvwprintw(snake.score, 1, 1, "%d ", score.score);
  return (0);
}

t_body		*tail_to_head(t_body *head, int x, int y, t_snake snake)
{
  t_body	*new_head;
  t_body	*tmp;

  new_head = init_body(x, y);
  new_head->next = head;
  tmp = new_head;
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  mvwprintw(snake.board, tmp->next->y, tmp->next->x, " ");
  free(tmp->next);
  tmp->next = NULL;
  return (new_head);
}
