#ifndef SO_LONG_H
# define SO_LONG_H
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

int	get_next_line(int fd, char **line);

#endif
