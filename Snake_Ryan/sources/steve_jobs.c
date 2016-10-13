/*
** steve_jobs.c for steve_jobs in /home/rouche-q/rendu/project_RYAN/Snake_Ryan/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Wed May 11 10:25:27 2016 Rouche-q
** Last update Wed May 11 12:56:32 2016 Rouche-q
*/

#include "snake.h"

t_score		init_score(t_score score)
{
  score.a_posx = 0;
  score.a_posy = 0;
  score.score = -1;
  return (score);
}

t_body		*add_body(t_body *python, t_score score)
{
  t_body	*head;
  
  head = init_body(score.a_posx, score.a_posy);
  head->next = python;
  return (head);
}


t_score		apple(t_snake snake, t_body *python, t_score score)
{
  if (score.score == -1)
    {
      score.a_posx = rand() % snake.x + 1;
      score.a_posy = rand() % snake.y + 1;
      mvwprintw(snake.board, score.a_posy, score.a_posx, "*");
      mvwprintw(snake.score, 1, 1, "%d", score.score);
      score.score = score.score + 1;
    }
  else if (python->x == score.a_posx && python->y == score.a_posy)
    {
      mvwprintw(snake.board, score.a_posy, score.a_posx, "*");
      score.a_posx = rand() % snake.x + 1;
      score.a_posy = rand() % snake.y + 1;
      mvwprintw(snake.board, score.a_posy, score.a_posx, "*");
      mvwprintw(snake.score, 1, 1, "%d", score.score);
      score.score = score.score + 1;
    }
  return (score);
}
