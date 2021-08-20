/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:38:32 by byahn             #+#    #+#             */
/*   Updated: 2021/08/20 23:27:18 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	file_linecount(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	linecount--;
	close(fd);
	return (linecount);
}

char	**alloc_columns(t_mlx *mlxs, char *file)
{
	char	**map;
	int		line_count;

	line_count = file_linecount(file);
	if (line_count <= 0)
		return (0);
	mlxs->map_height = line_count;
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		return (0);
	return (map);
}

int	check_file_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 5)
		return (0);
	if (file[--i] == 'r')
	{
		if (file[--i] == 'e')
		{
			if (file[--i] == 'b')
			{
				if (file[--i] == '.')
					return (1);
			}
		}
	}
	return (0);
}

void	load_map(t_mlx *mlxs, int argc, char *file)
{
	int		fd;
	int		i;

	if (!is_valid_file(argc, file))
		print_error("Not valid file\n");
	mlxs->map = alloc_columns(mlxs, file);
	if (mlxs->map == 0)
		print_error("Not valid map\n");
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &mlxs->map[i]))
		i++;
	mlxs->map_width = ft_strlen(mlxs->map[0]);
	mlxs->map[i] = 0;
	close(fd);
}
