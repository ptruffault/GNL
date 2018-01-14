/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:30:44 by ptruffau          #+#    #+#             */
/*   Updated: 2018/01/14 16:33:36 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd[argc];
	char *str;
	int i;
	int val;

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
		while ((val = get_next_line(fd[i], &str)) > 0)
		{
			ft_putstr(str);
			ft_putchar('\n');
		}
		close(fd[i++]);
	}
}
