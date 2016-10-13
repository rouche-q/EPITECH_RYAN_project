/*
** curse_exit.c for curse_exit in /home/rouche-q/rendu/project_RYAN/Snake_Ryan/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Wed May 11 15:12:44 2016 Rouche-q
** Last update Wed May 11 18:02:41 2016 Rouche-q
*/

#include "snake.h"

void		free_list(t_body *head)
{
  while (head->next != NULL)
    {
      free(head);
      head = head->next;
    }
  free(head);
}

void		curse_exit(t_body *head, t_snake snake)
{
  free_list(head);
  mvwprintw(snake.board, 0, 0, "caca");
  delwin(snake.board);
  delwin(snake.score);
  endwin();
}
