/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:35:59 by byahn             #+#    #+#             */
/*   Updated: 2021/08/20 21:36:15 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_mlx *mlxs, int x, int y)
{
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
		mlxs->img_tile, x * 100, y * 100);
}

void	draw_wall(t_mlx *mlxs, int x, int y)
{
	draw_tile(mlxs, x, y);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
		mlxs->img_wall, x * 100, y * 100);
}

void	draw_wall2(t_mlx *mlxs, int x, int y)
{
	draw_tile(mlxs, x, y);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
		mlxs->img_wall2, x * 100, y * 100);
}

void	draw_player(t_mlx *mlxs, int x, int y, int keycode)
{
	draw_tile(mlxs, x, y);
	if (keycode == KEY_W)
	{
		mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img_player_w, x * 100 + 25, y * 100 + 25);
	}
	else if (keycode == KEY_A)
	{
		mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img_player_a, x * 100 + 25, y * 100 + 25);
	}
	else if (keycode == KEY_S)
	{
		mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img_player_s, x * 100 + 25, y * 100 + 25);
	}
	else if (keycode == KEY_D)
	{
		mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img_player_d, x * 100 + 25, y * 100 + 25);
	}
}

void	draw_coin(t_mlx *mlxs, int x, int y)
{
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
		mlxs->img_tile, x * 100, y * 100);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
		mlxs->img_coin, x * 100, y * 100);
}
