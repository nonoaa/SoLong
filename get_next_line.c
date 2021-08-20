/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 22:19:52 by byahn             #+#    #+#             */
/*   Updated: 2021/08/20 22:59:21 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	ft_strcat(char **str, char c)
{
	char *tmp;
	int len;
	int i;

	i = 0;
	if (!(*str))
	{
		tmp = (char *)malloc(sizeof(char) * 2);
		tmp[0] = c;
		tmp[1] = '\0';
	}
	else
	{
		len = ft_strlen(*str);
		if(!(tmp = (char *)malloc(sizeof(char) * (len + 2))))
			return (0);
		while ((*str)[i])
		{
			tmp[i] = (*str)[i];
			i++;
		}
		tmp[i] = c;
		i++;
		tmp[i] = '\0';
	}
	free(*str);
	*str = tmp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int rd_out;
	char buffer;

	*line = 0;
	while((rd_out = read(fd, &buffer, 1)))
	{
		if (rd_out < 0)
			return (-1);
		if (buffer == '\n')
			return (1);
		ft_strcat(line, buffer);
	}
	return (0);
}
