#include "get_next_line.h"

char	*feed_that_buff(int const fd, char *buff, int *ret)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;

	*ret = read(fd, tmp, BUFF_SIZE);
	tmp[*ret] = '\0';
	tmp2 = buff;
	buff = ft_strjoin(buff, tmp);
	ft_strdel(&tmp2);
	return (buff);
}

int		get_next_line(int const fd, char ** line)
{
	static char		*buff = NULL;
	int				ret;
	char			*str;

	if (!line || fd < 0)
		return (-1);
	ret = 1;
	if (!buff)
		buff = ft_strnew(0);
	while (ret > 0)
	{
		if ((str = ft_strchr(buff, '\n')) != NULL)
		{
			*str = '\0';
			*line = ft_strdup(buff);
			ft_memmove(buff, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		buff = feed_that_buff(fd, buff, &ret);
	}
	return (ret);
}
