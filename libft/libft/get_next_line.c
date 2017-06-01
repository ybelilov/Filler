/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:05:36 by ybelilov          #+#    #+#             */
/*   Updated: 2017/01/19 19:05:41 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strjoin_mod(char *s1, char *s2)
{
	char	*ret;

	if (!(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcat(ret, s2);
	ft_strdel(&s1);
	return (ret);
}

static int	read_line(int fd, char **buf, char **line, char *pos)
{
	int	res;

	*line = ft_strdup(*buf);
	while (!pos)
	{
		if ((res = read(fd, *buf, BUFF_SIZE)) < 0)
			return (-1);
		if ((pos = ft_strchr(*buf, '\n')) == NULL && !res)
			return ((*buf)[0] = 0);
		else if (pos)
		{
			(*buf)[res] = res ? 0 : (*buf)[res];
			pos[0] = 0;
			*line = strjoin_mod(*line, *buf);
			ft_strcpy(*buf, pos + 1);
		}
		else
		{
			(*buf)[res] = res ? 0 : (*buf)[res];
			*line = strjoin_mod(*line, *buf);
			(*buf)[0] = 0;
		}
	}
	return (*line ? 1 : -1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buf;
	char		*pos;
	int			res;

	if (BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!buf)
		if (!(buf = ft_strnew(BUFF_SIZE)))
			return (-1);
	pos = ft_strchr(buf, '\n');
	if (pos)
	{
		*pos = 0;
		*line = ft_strdup(buf);
		ft_strcpy(buf, pos + 1);
		return (*line ? 1 : -1);
	}
	else
		res = read_line(fd, &buf, line, NULL);
	if (res == 0 && ft_strlen(*line) == 0)
		ft_strdel(&buf);
	if (res == -1)
		return (-1);
	return (res ? 1 : ft_strlen(*line) != 0);
}
