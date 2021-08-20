/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:39:26 by byahn             #+#    #+#             */
/*   Updated: 2021/08/20 21:40:01 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_file(int argc, char *file)
{
	if (argc != 2)
		return (0);
	else if (!check_file_name(file))
		return (0);
	return (1);
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

void	check_char_wall(t_mlx *mlxs, int i, int j)
{
	if (!is_valid_char(mlxs->map[i][j]))
		print_error("Map must be composed of only '0', '1', 'C', 'E', 'P'\n");
	if (i == 0 || i == mlxs->map_height - 1
		|| j == 0 || j == mlxs->map_width - 1)
	{
		if (mlxs->map[i][j] != '1')
			print_error("Map is not surrounded by wall.\n");
	}
}

void	check_essential(t_mlx *mlxs, int i, int j, int *essential)
{
	if (mlxs->map[i][j] == 'C')
		*essential |= 1;
	else if (mlxs->map[i][j] == 'P')
		*essential |= 2;
	else if (mlxs->map[i][j] == 'E')
		*essential |= 4;
}

void	check_map(t_mlx *mlxs)
{
	int	i;
	int	j;
	int	essential;

	i = 0;
	essential = 0;
	while (i < mlxs->map_height)
	{
		j = 0;
		if ((int)ft_strlen(mlxs->map[i]) != mlxs->map_width)
			print_error("Not a square map.\n");
		while (j < mlxs->map_width)
		{
			check_char_wall(mlxs, i, j);
			check_essential(mlxs, i, j, &essential);
			j++;
		}
		i++;
	}
	if (essential != 7)
		print_error("Map must have at least 1 'C', 'P', 'E'\n");
}
