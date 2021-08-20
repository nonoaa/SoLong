/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:36:39 by byahn             #+#    #+#             */
/*   Updated: 2021/08/21 01:33:35 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_end(t_mlx *mlxs, int x, int y)
{
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
		mlxs->img_tile, x * 100, y * 100);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
		mlxs->img_end, x * 100, y * 100);
}

void	draw_end2(t_mlx *mlxs, int x, int y)
{
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
		mlxs->img_tile, x * 100, y * 100);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
		mlxs->img_end2, x * 100, y * 100 + 1);
}

void	draw_tiles(t_mlx *mlxs, int i, int j)
{
	if (mlxs->map[i][j] == '1')
		draw_wall(mlxs, j, i);
	else if (mlxs->start == 0 && mlxs->map[i][j] == '0')
		draw_tile(mlxs, j, i);
	else if (mlxs->start == 0 && mlxs->map[i][j] == 'P')
	{
		draw_tile(mlxs, j, i);
		mlxs->player.x = j;
		mlxs->player.y = i;
	}
	else if (mlxs->start == 0 && mlxs->map[i][j] == 'C')
	{
		draw_coin(mlxs, j, i);
		mlxs->coins++;
	}
	else if (mlxs->map[i][j] == 'E')
		draw_end(mlxs, j, i);
	else if (mlxs->start == 0 && mlxs->map[i][j] == 'Z')
	{
		draw_tile(mlxs, j, i);
		mlxs->enemy.x = j;
		mlxs->enemy.y = i;
		mlxs->enemy.direction = KEY_D;
	}
}

void	draw_map(t_mlx *mlxs)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlxs->map_height)
	{
		j = 0;
		while (j < mlxs->map_width)
		{
			draw_tiles(mlxs, i, j);
			j++;
		}
		i++;
	}
	if (mlxs->start == 0)
	{
		draw_player(mlxs, mlxs->player.x, mlxs->player.y, KEY_D);
		mlx_string_put(mlxs->mlx, mlxs->win, mlxs->player.x,
			mlxs->player.y, 0xFFFFFF, ft_itoa(mlxs->movement));
		draw_enemy(mlxs, mlxs->enemy.x, mlxs->enemy.y);
	}
	mlxs->start = 1;
}

void	draw_map2(t_mlx *mlxs)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlxs->map_height)
	{
		j = 0;
		while (j < mlxs->map_width)
		{
			if (mlxs->map[i][j] == '1')
				draw_wall2(mlxs, j, i);
			else if (mlxs->map[i][j] == 'E')
				draw_end2(mlxs, j, i);
			j++;
		}
		i++;
	}
}
