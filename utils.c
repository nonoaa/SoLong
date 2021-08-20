/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:37:39 by byahn             #+#    #+#             */
/*   Updated: 2021/08/20 21:38:09 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sprite(t_mlx *mlxs)
{
	static int	cnt;

	if (cnt < 10)
		draw_map(mlxs);
	else
		draw_map2(mlxs);
	cnt++;
	if (cnt > 20)
		cnt = 0;
	return (0);
}

int	ft_close(t_mlx *mlxs)
{
	(void)mlxs;
	exit(0);
}

void	load_images(t_mlx *mlxs, int img_width, int img_height)
{
	mlxs->img_tile = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/tile.xpm", &img_width, &img_height);
	mlxs->img_wall = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/supply.xpm", &img_width, &img_height);
	mlxs->img_wall2 = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/supply2.xpm", &img_width, &img_height);
	mlxs->img_player_w = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/probe_w.xpm", &img_width, &img_height);
	mlxs->img_player_a = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/probe_a.xpm", &img_width, &img_height);
	mlxs->img_player_s = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/probe_s.xpm", &img_width, &img_height);
	mlxs->img_player_d = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/probe_d.xpm", &img_width, &img_height);
	mlxs->img_coin = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/mineral.xpm", &img_width, &img_height);
	mlxs->img_end = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/nexus_on.xpm", &img_width, &img_height);
	mlxs->img_end2 = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/nexus_off.xpm", &img_width, &img_height);
	mlxs->img_enemy_l = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/zergling_left.xpm", &img_width, &img_height);
	mlxs->img_enemy_r = mlx_xpm_file_to_image(mlxs->mlx,
			"./images/zergling_right.xpm", &img_width, &img_height);
}

void	print_error(char *str)
{
	printf("%s", str);
	exit(1);
}
