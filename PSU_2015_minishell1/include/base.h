/*
** base.h for base in /home/rouche-q/utiles/sources
** 
** Made by Rouche-q
** Login   <rouche-q@rouche-q>
** 
** Started on  Mon May  2 17:53:40 2016 Rouche-q
** Last update Thu May 12 10:21:20 2016 Rouche-q
*/

#ifndef BASE_H_
# define BASE_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#ifndef READ_SIZE
# define READ_SIZE (1024)
#endif

int		my_putchar(char c);
int		my_putstr(char *str);
int		my_strlentochar(char *str, char c);
int		my_strlen(char *str);
char		*my_strcpy(char *dest, char *src);
char		*get_next_line(int fd);
char		*my_realloc(char *str, int size);
int		my_strcompar(char *s1, char *s2);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_strconcat(char *s1, char *s2);
int		count_char(char *str, char limit);
int		count_words(char *str, char limit);
char		**my_str_to_wordtab(char *str, char limit);

#endif /* !BASE_H_ */
