##
## Makefile for Q_rougesh in /home/rouche-q/rendu/PSU/PSU_2015_minishell2/minishell1
## 
## Made by Rouche-q
## Login   <rouche-q@epitech.net>
## 
## Started on  Sun Mar 20 08:32:47 2016 Rouche-q
## Last update Wed Jun  8 19:57:27 2016 Rouche-q
##


NAME	=	mysh


CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Werror -Wextra -Wall
CFLAGS	+=	-Iinclude -pedantic

SRCS	=	sources/fctbase.c		\
		sources/get_next_line.c	 	\
		sources/get_env_list.c		\
		sources/my_strcompar.c		\
		sources/my_strncpy.c		\
		sources/my_strconcat.c		\
		sources/my_str_to_wordtab.c	\
		sources/main.c			\
		sources/getcmd.c		\
		sources/exit.c			\
		sources/env.c			\
		sources/my_execve.c		\
		sources/my_execve2.c		\
		sources/my_cd.c			\
		sources/multi_cmd.c		\

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
