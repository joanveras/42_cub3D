#ifndef CUBE3D_H
# define CUBE3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define ESC 65307

typedef enum e_hook_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_DESTROY = 17
}	t_hook_events;

typedef enum e_window
{
	WINDOW_WIDTH = 1024,
	WINDOW_HEIGHT = 720
}	t_window;

typedef struct s_program
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
}	t_program;

void	x11_connect(t_program *program);

int		safe_exit(t_program *program);
int		handle_key_inputs(int keycode, t_program *program);

char	**open_map(char *path);

#endif