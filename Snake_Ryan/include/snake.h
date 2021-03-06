/*
** snake.h for snake in /home/rouche-q/rendu/project_RYAN/Snake_Ryan
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Thu May  5 10:12:37 2016 Rouche-q
** Last update Wed May 11 18:42:00 2016 Rouche-q
*/

#ifndef SNAKE_H_
# define SNAKE_H_

# include <ncurses.h>
# include <curses.h>
# include "base.h"

typedef struct	s_body
{
  int		x;
  int		y;
  struct s_body *next;
}		t_body;

typedef struct	s_snake
{
  int		x;
  int		y;
  WINDOW	*board;
  WINDOW	*score;	
}		t_snake;

typedef struct	s_score
{
  int		a_posx;
  int		a_posy;
  int		score;
}		t_score;

int		init_win(t_snake *snake, int x, int y);
void		play(t_snake snake);
WINDOW		*init();
int		comp_keys(int c,t_snake snake);
t_snake		splitwin(WINDOW *win, t_snake snake);
t_body		*init_body(int x, int y);
t_body		*start_body(t_snake snake);
int		aff_all(t_snake snake, t_body *body, t_score score);
t_body		*tail_to_head(t_body *head, int x, int y, t_snake snake);
t_body		*go_up(t_body *head, t_snake snake ,int c);
t_body		*go_down(t_body *head, t_snake snake, int c);
t_body		*go_left(t_body *head, t_snake snake, int c);
t_body		*go_right(t_body *head, t_snake snake, int c);
t_body		*direction(t_body *head, t_snake snake, t_score score ,int c);
t_score		init_score(t_score score);
t_score		apple(t_snake snake, t_body *python, t_score score);
t_body		*add_body(t_body *python, t_score score);
int		collision(t_body *head, t_snake snake);
int		c_body(t_body *head);
int		c_wall(t_body *head, t_snake snake);
void		free_list(t_body *head);
void		curse_exit(t_body *head, t_snake snake);

#endif /* !SNAKE_H_ */
