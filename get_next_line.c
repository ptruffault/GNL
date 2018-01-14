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

char	*joinstr(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	len1 = (s1) ? ft_strlen(s1) : 0;
	len2 = ft_strlen(s2);
	result = ft_strnew(len1 + len2);
	if (result)
	{
		if (s1)
		{
			ft_strncpy(result, s1, len1);
			ft_strdel(&s1);
		}
		ft_strncpy(result + len1, s2, len2);
	}
	return (result);
}

int		ft_check_line(char **strbuff, char **line)
{
	char	*lim;

	lim = ft_strchr(*strbuff, '\n');
	if (lim)
	{
		*line = ft_strsub(*strbuff, 0, lim - *strbuff);
		ft_strcpy(*strbuff, lim + 1);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	static char	*strbuff;

	if (strbuff && ft_check_line(&strbuff, line))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		strbuff = joinstr(strbuff, buff);
		if (ft_check_line(&strbuff, line))
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (strbuff && *strbuff)
	{
		*line = ft_strdup(strbuff);
		ft_strdel(&strbuff);
		return (1);
	}
	if (strbuff)
		ft_strdel(&strbuff);
	return (0);
}