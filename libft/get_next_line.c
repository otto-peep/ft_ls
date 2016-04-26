/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pconin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:27:59 by pconin            #+#    #+#             */
/*   Updated: 2016/02/17 19:34:48 by pconin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "get_next_line.h"

static int		found_newline(char *tmp)
{
	int a;

	a = 0;
	while (tmp[a])
	{
		if (tmp[a] == SPLITTER || tmp[a] == '\0')
			break ;
		a++;
	}
	return (a);
}

static int		newline(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == SPLITTER)
			return (1);
		i++;
	}
	return (0);
}

static void		ft_read(int fd, char **tmp, int *ret)
{
	char buf[BUFF_SIZE + 1];
	char *rmb;

	rmb = NULL;
	while ((*ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[*ret] = '\0';
		rmb = *tmp;
		*tmp = ft_strjoin(*tmp, buf);
		free(rmb);
		rmb = NULL;
		if (newline(*tmp) == 1)
			break ;
	}
	return ;
}

int				get_next_line(int const fd, char **line)
{
	static char	*tmp[256];
	int			ret;
	char		*mem;

	ret = 0;
	mem = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > 256)
		return (-1);
	if (tmp[fd] == NULL)
		tmp[fd] = ft_strnew(BUFF_SIZE + 1);
	if (!(newline(tmp[fd])) && tmp[fd] != NULL)
		ft_read(fd, &tmp[fd], &ret);
	if (ret < 0 || tmp[fd] == NULL)
		return (-1);
	*line = ft_strsub(tmp[fd], 0, found_newline(tmp[fd]));
	if (!(ft_strlen(tmp[fd])) && ret == 0)
		return (0);
	mem = tmp[fd];
	tmp[fd] = ft_strsub(tmp[fd],
			found_newline(tmp[fd]) + 1, ft_strlen(tmp[fd]));
	free(mem);
	return (1);
}
