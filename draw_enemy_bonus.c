/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 23:35:43 by byahn             #+#    #+#             */
/*   Updated: 2021/08/21 00:10:16 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_enemy(t_mlx *mlxs, int x, int y)
{
	draw_tile(mlxs, x, y);
	if (mlxs->enemy.direction == KEY_D)
	{
		mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img_enemy_r, x * 100 + 25, y * 100 + 25);
	}
	else if (mlxs->enemy.direction == KEY_A)
	{
		mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img_enemy_l, x * 100 + 25, y * 100 + 25);
	}
}
