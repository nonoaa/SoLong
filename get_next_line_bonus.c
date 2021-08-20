/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 22:19:52 by byahn             #+#    #+#             */
/*   Updated: 2021/08/21 01:33:48 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcat(char **str, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	if (*str == 0)
	{
		tmp = (char *)malloc(sizeof(char) * 2);
		tmp[i++] = c;
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 2));
		if (!tmp)
			return (0);
		while ((*str)[i])
		{
			tmp[i] = (*str)[i];
			i++;
		}
		tmp[i++] = c;
	}
	tmp[i] = '\0';
	free(*str);
	*str = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int		rd_out;
	char	buffer;

	*line = 0;
	buffer = 0;
	rd_out = read(fd, &buffer, 1);
	while (rd_out)
	{
		if (rd_out < 0)
			return (-1);
		if (buffer == '\n')
			return (1);
		ft_strcat(line, buffer);
		rd_out = read(fd, &buffer, 1);
	}
	return (0);
}
