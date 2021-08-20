/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status_enemy_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:33:50 by byahn             #+#    #+#             */
/*   Updated: 2021/08/21 01:33:09 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_block_enemy(t_mlx *mlxs, int x, int y)
{
	if (mlxs->map[y][x] == '1'
		|| mlxs->map[y][x] == 'E' || mlxs->map[y][x] == 'C')
		return (1);
	return (0);
}

int	check_wall_enemy(int keycode, t_mlx *mlxs)
{
	if (keycode == KEY_D)
	{
		if (is_block_enemy(mlxs, mlxs->enemy.x + 1, mlxs->enemy.y))
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (is_block_enemy(mlxs, mlxs->enemy.x - 1, mlxs->enemy.y))
			return (1);
	}
	return (0);
}

int	check_end_enemy(int keycode, t_mlx *mlxs)
{
	if (keycode == KEY_A)
	{
		if (mlxs->map[mlxs->enemy.y][mlxs->enemy.x - 1]
				== 'P')
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (mlxs->map[mlxs->enemy.y][mlxs->enemy.x + 1]
				== 'P')
			return (1);
	}
	return (0);
}
