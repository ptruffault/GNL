#include <stdio.h>
#include "./get_next_line.h"
#include <fcntl.h>

int		main(int argc, const char *argv[])
{
	char	*line;
	int		fd = open(argv[1], O_RDONLY);

	while (get_next_line(fd, &line))
		printf("%s\n", line);
}
