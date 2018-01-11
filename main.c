#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd[argc];
	char *str;
	int i;

	i = 1;
	if (argc <= 1)
	{
		ft_putstr("usage: ./test [file] ...");
		return (-1);
	}
	while (i < argc)
	{
		if (!(fd[i] = open(argv[i], O_RDONLY)))
			return (-1);
		while (get_next_line(fd[i], &str) > 0)
		{
			ft_putstr(str);
			ft_putchar('\n');
			ft_putchar('\n');
		}
		close(fd[i++]);
	}
}
