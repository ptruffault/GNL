#include "get_next_line.h"

int		ft_malloc_again(char **save)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(*save))))
		return (0);
	ft_strcpy(tmp, *save);
	*save = NULL;
	free(*save);
	if (!(*save = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	ft_strcpy(*save, tmp);
	free(tmp);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int ret;
	static char *save;
	char buff[BUFF_SIZE];
	int i;

	i = 0;
	if (!(save))
	{	
		if (fd < 0 || (!save && !(save = ft_strnew(BUFF_SIZE))))
			return (-1);
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			ft_strncat(save, buff, ret);
			if (!(ft_malloc_again(&save)))
				return (-1);
		}
	}
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * i)))
		return (-1);
	i = 0;
	while (*save != '\0' && *save != '\n')
		(*line)[i++] = *save++;
	(*line)[i] = '\0';
	if (*save == '\n')
		*save++;
	else
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	int fd;
	char *str;

	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1);
	while (get_next_line(fd,&str) == 1)
	{
		ft_putstr(str);
		printf("\n");
	}
	return (0);
}
