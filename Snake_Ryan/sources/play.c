/*
** play.c for play in /home/rouche-q/rendu/project_RYAN/Snake_Ryan
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Thu May  5 10:43:11 2016 Rouche-q
** Last update Wed May 11 19:33:09 2016 Rouche-q
*/

#include "snake.h"

t_snake		splitwin(WINDOW *win, t_snake snake)
{
  snake.board = subwin(win, snake.y + 2, snake.x + 2, 0, 0);
  snake.score = subwin(win, 3, snake.x + 2, snake.y + 2, 0);
  box(snake.board, ACS_VLINE, ACS_HLINE);
  box(snake.score, ACS_VLINE, ACS_HLINE);
  mvwprintw(snake.score, 0, 1, "Score");
  return (snake);
}

WINDOW		*init()
{
  WINDOW	*win;

  win = initscr();
  noecho();
  keypad(win, TRUE);
  curs_set(0);
  return (win);
}

int		comp_keys(int c, t_snake snake)
{
  static int	k;

  nodelay(snake.board, TRUE);
  c = getch();
  if (c == k || c == ERR)
    return (k);
  else
    k = c;
  return (c);
}

void		play(t_snake snake)
{
  WINDOW*	win;
  t_body	*python;
  t_score	score;
  int		c;
  

  python = start_body(snake);
  score = init_score(score);
  win = init();
  snake = splitwin(win, snake);
  while (c != 'q')
    {
      c = comp_keys(c, snake);
      python = direction(python, snake, score ,c);
      score = apple(snake, python, score);
      aff_all(snake, python, score);
      wrefresh(snake.board);
      wrefresh(snake.score);
      timeout(100);
    }
  endwin();
}
