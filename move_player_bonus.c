/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:34:50 by byahn             #+#    #+#             */
/*   Updated: 2021/08/26 17:52:40 by byeongguk        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_movement(t_mlx *mlxs)
{
	char	*itoa;

	itoa = ft_itoa(mlxs->movement);
	mlx_string_put(mlxs->mlx, mlxs->win, mlxs->player.x * 100 + 10,
		mlxs->player.y * 100 + 10, 0x2ECC71, itoa);
	free(itoa);
}

void	print_end(char *str)
{
	printf("%s", str);
	exit(0);
}

void	move_player(t_mlx *mlxs, int keycode)
{
	if (check_end(keycode, mlxs))
		print_end("success!\n");
	if (check_enemy(keycode, mlxs))
		print_end("you lose.\n");
	if (check_coin(keycode, mlxs))
		(mlxs->coins)--;
	if (!(check_wall(keycode, mlxs)))
	{
		draw_tile(mlxs, mlxs->player.x, mlxs->player.y);
		mlxs->map[mlxs->player.y][mlxs->player.x] = '0';
		if (keycode == KEY_W)
			mlxs->player.y -= 1;
		else if (keycode == KEY_A)
			mlxs->player.x -= 1;
		else if (keycode == KEY_S)
			mlxs->player.y += 1;
		else if (keycode == KEY_D)
			mlxs->player.x += 1;
		mlxs->map[mlxs->player.y][mlxs->player.x] = 'P';
		(mlxs->movement++);
	}
	draw_player(mlxs, mlxs->player.x, mlxs->player.y, keycode);
	print_movement(mlxs);
}

void	move_enemy(t_mlx *mlxs)
{
	if (check_end_enemy(mlxs->enemy.direction, mlxs))
		exit(0);
	if (!(check_wall_enemy(mlxs->enemy.direction, mlxs)))
	{
		draw_tile(mlxs, mlxs->enemy.x, mlxs->enemy.y);
		mlxs->map[mlxs->enemy.y][mlxs->enemy.x] = '0';
		if (mlxs->enemy.direction == KEY_A)
			mlxs->enemy.x -= 1;
		else if (mlxs->enemy.direction == KEY_D)
			mlxs->enemy.x += 1;
		mlxs->map[mlxs->enemy.y][mlxs->enemy.x] = 'Z';
	}
	else
	{
		if (mlxs->enemy.direction == KEY_D)
			mlxs->enemy.direction = KEY_A;
		else
			mlxs->enemy.direction = KEY_D;
	}
	draw_enemy(mlxs, mlxs->enemy.x, mlxs->enemy.y);
}

int	deal_key(int keycode, t_mlx *mlxs)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		move_player(mlxs, keycode);
	return (0);
}
