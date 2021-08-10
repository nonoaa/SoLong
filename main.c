#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

# define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
typedef	struct s_player
{
	int		x;
	int		y;
}				t_player;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		cnt;
	t_player player;
	char	map[7][10]; 
}				t_mlx;

int	get_next_line(int fd, char **line);

void draw_map(t_mlx *mlxs);

char	map[7][10] = {"1111111111", "1000000001",
			"1000000001", "1P01001001", "1001000101", "10C00000C1", "1111111111"};
	

int		deal_key(int keycode, t_mlx *mlxs)
{
		int a;
		int b;

		if (keycode == KEY_ESC)
				exit(0);
		else if (keycode == KEY_W)
		{
				map[mlxs->player.y][mlxs->player.x] = '0';
				mlxs->player.y -= 1;
				map[mlxs->player.y][mlxs->player.x] = 'P';
				draw_map(mlxs);
				mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/player.xpm", &a, &b);	
				mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, mlxs->player.x*50+5, mlxs->player.y*50);
		
		}
		else if (keycode == KEY_A)
		{
				map[mlxs->player.y][mlxs->player.x] = '0';				
				mlxs->player.x -= 1;
				map[mlxs->player.y][mlxs->player.x] = 'P';
				draw_map(mlxs);
				mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/player.xpm", &a, &b);
			
				mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, mlxs->player.x*50+5, mlxs->player.y*50);
		
		}
		else if (keycode == KEY_S)
		{
				map[mlxs->player.y][mlxs->player.x] = '0';
				
				mlxs->player.y += 1;
				map[mlxs->player.y][mlxs->player.x] = 'P';
				
				draw_map(mlxs);
			mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/player.xpm", &a, &b);
			mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, mlxs->player.x*50+5, mlxs->player.y*50);
		}
		else if (keycode == KEY_D)
		{
				map[mlxs->player.y][mlxs->player.x] = '0';
				mlxs->player.x += 1;
				map[mlxs->player.y][mlxs->player.x] = 'P';
				
				draw_map(mlxs);
			mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/player.xpm", &a, &b);
			
				mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, mlxs->player.x*50+5, mlxs->player.y*50);
		}
		(mlxs->cnt)++;
		printf("cnt:%d\n", mlxs->cnt);
		return (0);
}

void	draw_map(t_mlx *mlxs)
{

	int	img_width;
	int	img_height;
	int		i = 0;
	int		j = 0;
	while (i < 7)
	{
			j = 0;
			while (j < 10)
			{
				if (map[i][j] == '1')
				{	
					mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/tree.xpm", &img_width, &img_height);
					mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, j * 50,  i * 50);			
				}
				else if (map[i][j] == '0')
				{
					mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/tile.xpm", &img_width, &img_height);
					mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, j * 50, i * 50);
				}
				else if (map[i][j] == 'P')
				{
					mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/tile.xpm", &img_width, &img_height);
					mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, j * 50, i * 50);
				
					mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/player.xpm", &img_width, &img_height);
					mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, j * 50 + 5, i * 50);
				}
				else if (map[i][j] == 'C')
				{
					mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/tile.xpm", &img_width, &img_height);
					mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, j * 50, i * 50);
				
					mlxs->img = mlx_xpm_file_to_image(mlxs->mlx, "./images/coin.xpm", &img_width, &img_height);
					mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, j * 50, i * 50);
					
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

int		main(int argc, char *argv[])
{
	t_mlx	mlxs;
	mlxs.cnt = 0;
	mlxs.mlx = mlx_init();

	mlxs.win = mlx_new_window(mlxs.mlx, 50*10, 50*7, "so_long");
	int i = 0;
	int j = 0;
	mlxs.player.x = 1;
	mlxs.player.y = 3;
draw_map(&mlxs);
//	mlx_key_hook(mlxs.win, &deal_key, &mlxs);
	mlx_hook(mlxs.win, 2, 0, &deal_key, &mlxs);
	mlx_hook(mlxs.win, 17, 0, &ft_close, &mlxs);

	mlx_loop(mlxs.mlx);
	return (0);
}
