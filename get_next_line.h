#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 3

#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
void 	*ft_memchr(const void *s, int c, size_t n);
void	ft_putstr(const char *str);
char	*ft_strnew(int len);
char	*ft_strcpy(char *src, char *dest);
char 	*ft_strncat(char *dest, const char *src, size_t n);
int	ft_strlen(char *str);
#endif
