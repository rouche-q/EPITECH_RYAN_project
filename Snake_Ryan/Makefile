##
## Makefile for sources in /home/rouche-q/utiles/sources
## 
## Made by Rouche-q
## Login   <rouche-q@epitech.net>
## 
## Started on  Mon May  2 17:38:41 2016 Rouche-q
## Last update Wed May 11 17:33:36 2016 Rouche-q
##


CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Wextra -Wall -Werror -ansi -pedantic -Iinclude -lncurses -g3

LDFLAGS	=

NAME	=	snake

SRCS	=	sources/main.c		\
		sources/play.c		\
		sources/fctbase.c	\
		sources/my_getnbr.c	\
		sources/snake_body.c	\
		sources/direction.c	\
		sources/steve_jobs.c	\
		sources/colision.c	\
		sources/curse_exit.c	

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:	
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
