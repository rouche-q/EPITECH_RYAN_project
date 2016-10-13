##
## Makefile for sources in /home/rouche-q/utiles/sources
## 
## Made by Rouche-q
## Login   <rouche-q@epitech.net>
## 
## Started on  Mon May  2 17:38:41 2016 Rouche-q
## Last update Thu May 19 11:14:15 2016 Rouche-q
##


CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Wextra -Wall -Werror -ansi -pedantic -Iinclude

LDFLAGS	=

NAME	=	mysh

SRCS	=	sources/fctbase.c		\
		sources/get_next_line.c		\
		sources/my_strconcat.c		\
		sources/my_strcompar.c		\
		sources/my_strncpy.c		\
		sources/my_str_to_wordtab.c	\
		sources/main.c			\
		sources/get_env_list.c		\
		sources/getcmd.c		\
		sources/exit.c			\
		sources/env.c			\
		sources/my_execve.c

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
