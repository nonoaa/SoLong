/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:34:50 by byahn             #+#    #+#             */
/*   Updated: 2021/08/31 14:58:57 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_end(char *str)
{
	printf("%s", str);
	exit(0);
}

void	move_player(t_mlx *mlxs, int keycode)
{
	if (check_end(keycode, mlxs))
		print_end("success!\n");
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
		printf("Movement:%d\n", mlxs->movement);
	}
	draw_player(mlxs, mlxs->player.x, mlxs->player.y, keycode);
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
