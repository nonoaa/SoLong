/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:59:17 by byahn             #+#    #+#             */
/*   Updated: 2021/08/20 23:18:50 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_mlx *mlxs, int argc, char *file)
{
	load_map(mlxs, argc, file);
	check_map(mlxs);
	mlxs->mlx = mlx_init();
	mlxs->movement = 0;
	mlxs->win = mlx_new_window(mlxs->mlx,
			100 * mlxs->map_width, 100 * mlxs->map_height, "so_long");
	mlxs->start = 0;
	mlxs->coins = 0;
	load_images(mlxs, 0, 0);
	draw_map(mlxs);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlxs;

	initialize(&mlxs, argc, argv[1]);
	mlx_hook(mlxs.win, KEY_PRESS, 0, &deal_key, &mlxs);
	mlx_hook(mlxs.win, KEY_EXIT, 0, &ft_close, &mlxs);
	mlx_loop_hook(mlxs.mlx, &sprite, &mlxs);
	mlx_loop(mlxs.mlx);
	return (0);
}
