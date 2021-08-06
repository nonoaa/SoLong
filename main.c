#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

# define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		cnt;
}				t_mlx;

typedef	struct s_player
{
	int		x;
	int		y;
	int		cnt;
}				t_player;

int	get_next_line(int fd, char **line);

int x = 0;
int y = 0;

int		deal_key(int keycode, t_mlx *mlxs)
{
		if (keycode == KEY_ESC)
				exit(0);
		else if (keycode == KEY_W)
				;
		else if (keycode == KEY_A)
				;
		else if (keycode == KEY_S)
		{
				y += 50;
				mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, x, y);
		}
		else if (keycode == KEY_D)
		{
				x += 50;
				mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, x, y);
		}
		(mlxs->cnt)++;
		printf("cnt:%d\n", mlxs->cnt);
		return (0);
}

int		main(int argc, char *argv[])
{
	t_mlx	mlxs;

	int	img_width;
	int	img_height;
	
	mlxs.cnt = 0;
	mlxs.mlx = mlx_init();
	mlxs.win = mlx_new_window(mlxs.mlx, 1200, 600, "so_long");
	mlxs.img = mlx_xpm_file_to_image(mlxs.mlx, "./images/tile.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlxs.mlx, mlxs.win, mlxs.img ,0, 0);
	mlx_key_hook(mlxs.win, &deal_key, &mlxs);

	mlx_loop(mlxs.mlx);
	return (0);
}
