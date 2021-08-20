/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:33:50 by byahn             #+#    #+#             */
/*   Updated: 2021/08/20 21:34:18 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_wall_or_end(t_mlx *mlxs, int x, int y)
{
	if (mlxs->map[y][x] == '1' || mlxs->map[y][x] == 'E')
		return (1);
	return (0);
}

int	check_wall(int keycode, t_mlx *mlxs)
{
	if (keycode == KEY_W)
	{
		if (is_wall_or_end(mlxs, mlxs->player.x, mlxs->player.y - 1))
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (is_wall_or_end(mlxs, mlxs->player.x - 1, mlxs->player.y))
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (is_wall_or_end(mlxs, mlxs->player.x, mlxs->player.y + 1))
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (is_wall_or_end(mlxs, mlxs->player.x + 1, mlxs->player.y))
			return (1);
	}
	return (0);
}

int	check_end(int keycode, t_mlx *mlxs)
{
	if (keycode == KEY_W)
	{
		if (mlxs->map[mlxs->player.y - 1][mlxs->player.x]
				== 'E' && mlxs->coins <= 0)
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (mlxs->map[mlxs->player.y][mlxs->player.x - 1]
				== 'E' && mlxs->coins <= 0)
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (mlxs->map[mlxs->player.y + 1][mlxs->player.x]
				== 'E' && mlxs->coins <= 0)
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (mlxs->map[mlxs->player.y][mlxs->player.x + 1]
				== 'E' && mlxs->coins <= 0)
			return (1);
	}
	return (0);
}

int	check_enemy(int keycode, t_mlx *mlxs)
{
	if (keycode == KEY_W)
	{
		if (mlxs->map[mlxs->player.y - 1][mlxs->player.x] == 'Z')
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (mlxs->map[mlxs->player.y][mlxs->player.x - 1] == 'Z')
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (mlxs->map[mlxs->player.y + 1][mlxs->player.x] == 'Z')
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (mlxs->map[mlxs->player.y][mlxs->player.x + 1] == 'Z')
			return (1);
	}
	return (0);
}

int	check_coin(int keycode, t_mlx *mlxs)
{
	if (keycode == KEY_W)
	{
		if (mlxs->map[mlxs->player.y - 1][mlxs->player.x] == 'C')
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (mlxs->map[mlxs->player.y][mlxs->player.x - 1] == 'C')
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (mlxs->map[mlxs->player.y + 1][mlxs->player.x] == 'C')
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (mlxs->map[mlxs->player.y][mlxs->player.x + 1] == 'C')
			return (1);
	}
	return (0);
}
