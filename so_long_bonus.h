/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:59:50 by byahn             #+#    #+#             */
/*   Updated: 2021/08/21 00:18:47 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define KEY_PRESS 2
# define KEY_EXIT 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		direction;
}	t_enemy;

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
	t_enemy		enemy;
	int			map_height;
	int			map_width;
	char		**map;
}	t_mlx;

int		is_wall_or_end(t_mlx *mlxs, int x, int y);
int		is_block_enemy(t_mlx *mlxs, int x, int y);
int		check_enemy(int keycode, t_mlx *mlxs);
int		check_wall_enemy(int keycode, t_mlx *mlxs);
int		check_end_enemy(int keycode, t_mlx *mlxs);
int		check_wall(int keycode, t_mlx *mlxs);
int		check_end(int keycode, t_mlx *mlxs);
int		check_coin(int keycode, t_mlx *mlxs);
void	move_player(t_mlx *mlxs, int keycode);
void	move_enemy(t_mlx *mlxs);
int		deal_key(int keycode, t_mlx *mlxs);
void	draw_tile(t_mlx *mlxs, int x, int y);
void	draw_wall(t_mlx *mlxs, int x, int y);
void	draw_wall2(t_mlx *mlxs, int x, int y);
void	draw_player(t_mlx *mlxs, int x, int y, int keycode);
void	draw_coin(t_mlx *mlxs, int x, int y);
void	draw_end(t_mlx *mlxs, int x, int y);
void	draw_end2(t_mlx *mlxs, int x, int y);
void	draw_tiles(t_mlx *mlxs, int i, int j);
void	draw_map(t_mlx *mlxs);
void	draw_map2(t_mlx *mlxs);
void	draw_enemy(t_mlx *mlxs, int x, int y);
int		sprite(t_mlx *mlxs);
int		ft_close(t_mlx *mlxs);
void	load_images(t_mlx *mlxs, int img_width, int img_height);
int		file_linecount(char *file);
void	print_error(char *str);
char	**alloc_columns(t_mlx *mlxs, char *file);
int		check_file_name(char *file);
int		is_valid_file(int argc, char *file);
void	load_map(t_mlx *mlxs, int argc, char *file);
int		is_valid_char(char c);
void	check_char_wall(t_mlx *mlxs, int i, int j);
void	check_essential(t_mlx *mlxs, int i, int j, int *essential);
void	check_map(t_mlx *mlxs);
void	initialize(t_mlx *mlxs, int argc, char *file);
int		ft_strlen(char *str);
int		ft_strcat(char **str, char c);
char	*ft_itoa(int n);
int		get_next_line(int fd, char **line);

#endif
