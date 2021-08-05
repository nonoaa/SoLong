#include <mlx.h>

int        main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	int	img_width;
	int	img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 800, "so_long");
	img = mlx_png_file_to_image(mlx, "./images/map.png", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img ,720, 480);
	mlx_loop(mlx);
	return (0);
}
