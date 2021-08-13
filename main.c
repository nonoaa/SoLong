/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:59:17 by byahn             #+#    #+#             */
/*   Updated: 2021/08/13 18:41:33 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define KEY_PRESS 2
#define KEY_EXIT 17
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
	void		*img_tile;
	void		*img_wall;
	void		*img_wall2;
	void		*img_player_w;
	void		*img_player_a;
	void		*img_player_s;
	void		*img_player_d;
	void		*img_coin;
	void		*img_end;
	void		*img_end2;
	void		*img_enemy_l;
	void		*img_enemy_r;
	int			movement;
	int			start;
	int			coins;
	t_player	player;
	int			map_height;
	int			map_width;
	char		**map;
}	t_mlx;

int		get_next_line(int fd, char **line);
void	draw_map(t_mlx *mlxs);
void	draw_tile(t_mlx *mlxs, int x, int y);
void	draw_player(t_mlx *mlxs, int x, int y, int keycode);
size_t	ft_strlen(char *str);

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

void	move_player(t_mlx *mlxs, int keycode)
{
	if (check_end(keycode, mlxs))
		exit(0);
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
		draw_player(mlxs, mlxs->player.x, mlxs->player.y, KEY_D);
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

int	file_linecount(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	linecount--;
	close(fd);
	return (linecount);
}

char	**alloc_columns(t_mlx *mlxs, char *file)
{
	char	**map;
	int		line_count;

	line_count = file_linecount(file);
	if (line_count <= 0)
		return (0);
	mlxs->map_height = line_count;
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		return (0);
	return (map);
}

int	check_map(t_mlx *mlxs, char *file)
{
	char	**map;
	int		fd;
	int		i;

	mlxs->map = alloc_columns(mlxs, file);
	if (map == 0)
		return (0);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &mlxs->map[i++]))
		;
	mlxs->map_width = ft_strlen(mlxs->map[0]);
	mlxs->map[i] = 0;
	close(fd);
	return (1);
}

void	initialize(t_mlx *mlxs, int argc, char *file_name)
{
	if (!check_map(mlxs, file_name))
		exit(1);
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
