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

int	ft_find_save(t_list **save, int fd)
{
	while ((*save)->next != NULL)
	{
		*save = (*save)->next;
		if ((*save)->fd == fd)
			return (1);
	}
	while ((*save)->prev != NULL)
	{
		*save = (*save)->prev;
		if ((*save)->fd == fd)
			return (1);
	}
	return (0);
}

t_list	*ft_new_file(t_list **lst, int fd)
{

	char	buff[BUFF_SIZE];
	int	ret;
 
	if (!(*lst = (t_list *)malloc(sizeof(t_list *)))
	|| fd < 0 || !((*lst)->text = ft_strnew(BUFF_SIZE)))
		return (NULL);
	(*lst)->fd = fd;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ft_strncat((*lst)->text, buff, ret);
		if (!(ft_malloc_again((&(*lst)->text))))
			return (NULL);
	}
	(*lst)->next = NULL;
	if (ret == -1)
		return (NULL);
	return (*lst);
}


int	get_next_line(const int fd, char **line)
{
	static t_list *save;
	t_list *tmp;
	int i;

	i = 0;
	if (!(save))
	{
		ft_new_file(&save, fd);
		save->prev = NULL;
	}
	if ((save && save->fd != fd && ft_find_save(&save, fd) == 0)) 
	{
		if (!(tmp = (t_list *)malloc(sizeof(t_list *))))
			return (-1);
		tmp = save;
		ft_new_file(&save->next, fd);
		save = save->next;
		save->prev = tmp;
	}
	if (!(*line = (char *)malloc(sizeof(char) * ft_strlen(save->text))))
		return (-1);
	while (*save->text != '\0' && *save->text != '\n')
		(*line)[i++] = *save->text++;
	(*line)[i] = '\0';
	if (*save->text == '\n')
		*save->text++;
	else
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	int fd;
	int fd2;
	char *str;

	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1);
	if (!(fd2 = open(argv[2], O_RDONLY)))
		return (-1);
	while (get_next_line(fd,&str) > 0)
	{
		printf("%s\n", str);
		printf("%i\n", get_next_line(fd2, &str));
		
		printf("\n%s\n", str);
	}
	return (0);
}
