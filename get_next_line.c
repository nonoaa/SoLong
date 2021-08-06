/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:49:33 by byahn             #+#    #+#             */
/*   Updated: 2021/06/09 13:47:09 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_copy_line(t_buff *find, char **line)
{
	size_t		i;
	size_t		j;
	int			is_newline;

	i = ft_strlen(*line);
	if (!ft_realloc(line, i))
		return (-1);
	is_newline = 0;
	j = 0;
	while (find->buffer[j])
	{
		(*line)[i] = find->buffer[j];
		if (find->buffer[j++] == '\n')
		{
			is_newline = 1;
			break ;
		}
		i++;
	}
	(*line)[i] = '\0';
	i = 0;
	while (find->buffer[j])
		find->buffer[i++] = find->buffer[j++];
	find->buffer[i] = '\0';
	return (is_newline);
}

t_buff		*ft_find_buffer(int fd, t_buff *buffer)
{
	if (fd == buffer->fd)
		return (buffer);
	if (!buffer->next)
		return (buffer->next = ft_lstnew(fd));
	return (ft_find_buffer(fd, buffer->next));
}

void		ft_list_remove_if(t_buff **head, int fd)
{
	t_buff	*curr;
	t_buff	*tmp;

	while (*head && (*head)->fd == fd)
	{
		curr = *head;
		*head = (*head)->next;
		free(curr);
	}
	curr = *head;
	while (curr && curr->next)
	{
		if (curr->next->fd == fd)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			free(tmp);
		}
		curr = curr->next;
	}
}

int			rd_error(char **line, t_buff **head, int fd)
{
	if (*line)
		free(*line);
	*line = 0;
	ft_list_remove_if(head, fd);
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static t_buff	*head;
	t_buff			*find;
	int				out;
	int				rd_out;

	if (BUFFER_SIZE <= 0 || fd < 0
			|| !line || (!head && !(head = ft_lstnew(fd)))
			|| !(find = ft_find_buffer(fd, head)))
		return (-1);
	*line = 0;
	if ((out = ft_copy_line(find, line)))
		return (out);
	while ((rd_out = read(fd, find->buffer, BUFFER_SIZE)))
	{
		if (rd_out < 0)
			return (rd_error(line, &head, fd));
		find->buffer[rd_out] = '\0';
		if ((out = ft_copy_line(find, line)))
			return (out);
	}
	ft_list_remove_if(&head, fd);
	return (out);
}
