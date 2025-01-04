#ifndef CUBE3D_H
# define CUBE3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include "structs.h"



// Allowed ?
#include <math.h>



# define ESC 65307

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 720

# define textureWidth 64
# define textureHeight 64

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05



void	x11_connect(t_program *program);
void	load_img_data(t_img_data *image);
void	clear_image(t_img_data *img, int color);
void	perform_dda(t_program *program, int *side);
void	load_texture_data(t_texture_data *texture);
void	floor_and_ceiling_casting(t_program *program);
void	w_conditions(t_program *program, int keycode);
void	s_conditions(t_program *program, int keycode);
void	d_conditions(t_program *program, int keycode);
void	a_conditions(t_program *program, int keycode);
void	load_wall_data(t_program *program, char *path);
void	load_floor_and_ceiling_data(t_program *program);
void	calc_texel_point(t_floor_and_ceiling_casting *fc);
void	put_pixel(t_img_data *img, int x, int y, int color);
void	calc_step_and_initial_side_dist(t_program *program);
void	load_game_and_raycast_initial_info(t_program *program);
void	load_texture(void *mlx, t_texture_data *texture,char *path);
void	calc_dist_of_perpendicular_ray(t_program *program, int side);
void	load_img(void *mlx, t_img_data *image, int width, int height);
void	calc_where_the_wall_was_hit(t_program *program, int side, double *wallX);
void	calc_row_distance(t_program *program, t_floor_and_ceiling_casting *fc, int y);
void	transform_image_floor_side(t_program *program, t_floor_and_ceiling_casting *fc, int x, int y);
void	transform_image_ceiling_side(t_program *program, t_floor_and_ceiling_casting *fc, int x, int y);
void	calc_vertical_line_and_transform_image(t_program *program, int x, double wallX, int lineHeight);

int		safe_exit(t_program *program);
int		wall_casting(t_program *program);
int		handle_key_inputs(int keycode, t_program *program);
int		get_texel_color(t_texture_data *tex, int texPosX, int texPosY);

char	**open_map(char *path);

#endif