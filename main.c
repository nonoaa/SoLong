/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:59:17 by byahn             #+#    #+#             */
/*   Updated: 2021/08/11 18:49:40 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			cnt;
	t_player	player;
	char		map[7][10];
}	t_mlx;

int		get_next_line(int fd, char **line);

void	draw_map(t_mlx *mlxs);
void	draw_tile(t_mlx *mlxs, int x, int y);

char	map[7][10] = {"1111111111", "1E0C00CCC1",
			"1000000001", "1P01001001", "1001000101", "10C00000C1", "1111111111"};

int	check_wall(int keycode, t_mlx *mlxs)
{
	if (keycode == KEY_W)
	{
		if (map[mlxs->player.y - 1][mlxs->player.x] == '1')
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (map[mlxs->player.y][mlxs->player.x - 1] == '1')
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (map[mlxs->player.y + 1][mlxs->player.x] == '1')
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (map[mlxs->player.y][mlxs->player.x + 1] == '1')
			return (1);
	}
	return (0);
}

int	check_end(int keycode, t_mlx *mlxs)
{
	if (keycode == KEY_W)
	{
		if (map[mlxs->player.y - 1][mlxs->player.x] == 'E')
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (map[mlxs->player.y][mlxs->player.x - 1] == 'E')
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (map[mlxs->player.y + 1][mlxs->player.x] == 'E')
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (map[mlxs->player.y][mlxs->player.x + 1] == 'E')
			return (1);
	}
	return (0);
}

int	deal_key(int keycode, t_mlx *mlxs)
{
	int	img_width;
	int	img_height;

	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W)
	{
		if (check_end(keycode, mlxs))
			exit(0);
		if (!(check_wall(keycode, mlxs)))
		{
			draw_tile(mlxs, mlxs->player.x, mlxs->player.y);
			map[mlxs->player.y][mlxs->player.x] = '0';
			mlxs->player.y -= 1;
			map[mlxs->player.y][mlxs->player.x] = 'P';
			(mlxs->cnt++);
		}
		mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/tile.xpm", &img_width, &img_height);
		mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, mlxs->player.x * 100, mlxs->player.y * 100);
		mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/probe_w.xpm", &img_width, &img_height);
	}
	else if (keycode == KEY_A)
	{
		if (check_end(keycode, mlxs))
			exit(0);
		if (!(check_wall(keycode, mlxs)))
		{
			draw_tile(mlxs, mlxs->player.x, mlxs->player.y);
			map[mlxs->player.y][mlxs->player.x] = '0';
			mlxs->player.x -= 1;
			map[mlxs->player.y][mlxs->player.x] = 'P';
			(mlxs->cnt++);
		}
		mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/tile.xpm", &img_width, &img_height);
		mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, mlxs->player.x * 100, mlxs->player.y * 100);
		mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/probe_a.xpm", &img_width, &img_height);
	}
	else if (keycode == KEY_S)
	{
		if (check_end(keycode, mlxs))
			exit(0);
		if (!(check_wall(keycode, mlxs)))
		{
			draw_tile(mlxs, mlxs->player.x, mlxs->player.y);
			map[mlxs->player.y][mlxs->player.x] = '0';
			mlxs->player.y += 1;
			map[mlxs->player.y][mlxs->player.x] = 'P';
			(mlxs->cnt++);
		}
		mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/tile.xpm", &img_width, &img_height);
		mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, mlxs->player.x * 100, mlxs->player.y * 100);
		mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/probe_s.xpm", &img_width, &img_height);
	}
	else if (keycode == KEY_D)
	{
		if (check_end(keycode, mlxs))
			exit(0);
		if (!(check_wall(keycode, mlxs)))
		{
			draw_tile(mlxs, mlxs->player.x, mlxs->player.y);
			map[mlxs->player.y][mlxs->player.x] = '0';
			mlxs->player.x += 1;
			map[mlxs->player.y][mlxs->player.x] = 'P';
			(mlxs->cnt++);
		}
		mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/tile.xpm", &img_width, &img_height);
		mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, mlxs->player.x * 100, mlxs->player.y * 100);
		mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/probe_d.xpm", &img_width, &img_height);
	}
	else
		return (0);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
		mlxs->img, mlxs->player.x * 100, mlxs->player.y * 100);
	printf("cnt:%d\n", mlxs->cnt);
	return (0);
}

void	draw_tile(t_mlx *mlxs, int x, int y)
{
	int	img_width;
	int	img_height;
	
	mlxs->img = mlx_xpm_file_to_image(mlxs->mlx,
		"./images/tile.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, x * 100, y * 100);
}

void	draw_wall(t_mlx *mlxs, int x, int y)
{
	int	img_width;
	int	img_height;
	
	draw_tile(mlxs, x, y);
	mlxs->img = mlx_xpm_file_to_image(mlxs->mlx,
		"./images/supply.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, x * 100, y * 100);
}

void	draw_player(t_mlx *mlxs, int x, int y)
{
	int	img_width;
	int	img_height;
	
	draw_tile(mlxs, x, y);
	mlxs->img = mlx_xpm_file_to_image(mlxs->mlx,
		"./images/probe_d.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, x * 100, y * 100);
}

void	draw_coin(t_mlx *mlxs, int x, int y)
{
	int	img_width;
	int	img_height;
	
	mlxs->img = mlx_xpm_file_to_image(mlxs->mlx,
		"./images/tile.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, x * 100, y * 100);
	mlxs->img = mlx_xpm_file_to_image(mlxs->mlx,
		"./images/mineral.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, x * 100, y * 100);
}

void	draw_end(t_mlx *mlxs, int x, int y)
{
	int	img_width;
	int	img_height;
	
	mlxs->img = mlx_xpm_file_to_image(mlxs->mlx,
		"./images/tile.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, x * 100, y * 100);
	mlxs->img = mlx_xpm_file_to_image(mlxs->mlx,
		"./images/nexus_on.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlxs->mlx, mlxs->win,
			mlxs->img, x * 100, y * 100);

}

void	draw_map(t_mlx *mlxs)
{
	int	i;
	int	j;
	static int start;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 10)
		{
			if (map[i][j] == '1')
				draw_wall(mlxs, j, i);
			else if (map[i][j] == '0')
				draw_tile(mlxs, j, i);
			else if (map[i][j] == 'P')
			{
				if (start == 0)
					draw_player(mlxs, j, i);
				start = 1;
			}
			else if (map[i][j] == 'C')
				draw_coin(mlxs, j, i);
			else if (map[i][j] == 'E')
				draw_end(mlxs, j, i);
			else
			{
				printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	ft_close(t_mlx mlxs)
{
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlxs;
	mlxs.cnt = 0;
	mlxs.mlx = mlx_init();
	mlxs.win = mlx_new_window(mlxs.mlx, 100*10, 100*7, "so_long");
	mlxs.player.x = 1;
	mlxs.player.y = 3;
	draw_map(&mlxs);
//	mlx_key_hook(mlxs.win, &deal_key, &mlxs);
	mlx_hook(mlxs.win, 2, 0, &deal_key, &mlxs);
	mlx_hook(mlxs.win, 17, 0, &ft_close, &mlxs);

	mlx_loop(mlxs.mlx);
	return (0);
}
