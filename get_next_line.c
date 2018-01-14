/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:43:08 by ptruffau          #+#    #+#             */
/*   Updated: 2018/01/14 17:21:24 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_EOL(char **text, char **line)
{
	char	*eol;

	if ((eol = ft_strchr(*text, '\n')))
	{
		*line = ft_strsub(*text, 0, eol - *text);
		ft_strcpy(*text, eol + 1);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	static char	*text;
	char		*tmp;

	if (text && ft_check_EOL(&text, line))
		return (1);
	if (!text)
		text = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = text;
		text = ft_strjoin(text, buff);
		ft_strdel(&tmp);
		if (ft_check_EOL(&text, line))
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (text && *text)
	{
		*line = ft_strdup(text);
		ft_strdel(&text);
		return (1);
	}
	if (text)
		ft_strdel(&text);
	return (0);
}
