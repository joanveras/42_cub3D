/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:58:57 by marcribe          #+#    #+#             */
/*   Updated: 2025/05/15 21:00:02 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "structs.h"
# include <math.h>

# define ESC 65307
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.066
# define TEXTURE_WEST 0
# define TEXTURE_EAST 1
# define TEXTURE_NORTH 2
# define TEXTURE_SOUTH 3
# define INVALID_PATH "Invalid texture path\n"
# define INVALID_COLOR_FORMAT "Invalid color format\n"
# define INVALID_RGB_RANGE "Invalid RGB range\n"
# define FLOOR_TEXTURE "assets/textures/dark_browntile.xpm"

/*
** File validations
*/
void	validate_file(t_program *program);
void	is_a_file(t_program *program, char *path);
void	check_first_info(t_program *program, int *i);
void	get_player_info(t_program *program, char **map);
void	validate_rgb_range(t_program *program, int *rgb);
void	check_map_is_closed(t_program *program, char **map);
void	check_for_duplicates(t_program *program, char **map);
void	check_file_extension(t_program *program, char *line);
void	error_message(t_program *program, const char *message);
void	check_for_invalid_characters(t_program *program, char **map);
void	check_path(t_program *program, char c1, char c2, char *line);
void	check_abbrev(t_program *program, char *line, int *dir_counter);
void	clean_and_error(t_program *p, char *s, char *l, int *r);
void	remain_something(t_program *p, char *s, char *l, int *r);
void	set_rgb(int *rgb, const char *s, int i);

int		is_next_digit(t_program *p, const char *s);
int		rgb_to_int(int *nums);
int		*check_colors(t_program *program, char **map, int i);

/*
** Input Keys
*/
void	left(t_program *program, int keycode);
void	right(t_program *program, int keycode);
void	foward(t_program *program, int keycode);
void	backward(t_program *program, int keycode);
int		handle_key_inputs(int keycode, t_program *program);

/*
** Raycasting functions
*/
void	calc_texel_point(t_casting *casting);
void	clear_image(t_img_data *img, int color);
void	ceiling_floor_casting(t_program *program);
void	calc_row_distance(t_program *program, t_casting *casting, int y);
void	transform_image_floor(t_program *program, t_casting *casting);
void	transform_image_ceiling(t_program *program, t_casting *casting);
void	perform_dda(t_program *program, int *side);
void	calc_step_and_initial_side_dist(t_program *program);
void	calc_dist_of_perpendicular_ray(t_program *program, int side);
void	calc_wall_hit(t_program *program, int side, double *wall_x);
void	draw_vertical_line(t_program *program, t_draw_params *params);
int		wall_casting(t_program *program);
int		bonus_wall_casting(t_program *program);
int		get_color(t_texture_data tex, int tex_pos_x, int tex_pos_y);

/*
** Helper functions
*/
void	free_file(t_map *map);
void	load_img_data(t_img_data *image);
void	load_textures(t_program *program);
void	transform_c_f(t_program *program);
void	bonus_load_textures(t_program *program);
void	free_textures_paths(t_program *program);
void	load_texture_data(t_texture_data *texture);
void	put_pixel(t_img_data *img, int x, int y, int color);
void	load_texture(void *mlx, t_texture_data *texture, char *path);
void	load_img(void *mlx, t_img_data *image, int width, int height);
int		get_texel_color(t_program *program, t_texture_data *tex,
			int tex_pos_x, int tex_pos_y);
void	x11_connect(t_program *program);
int		safe_exit(t_program *program);
int		bonus_safe_exit(t_program *program);
char	**open_file(char *path);

/*
** New struct for draw parameters
*/
typedef struct s_draw_params
{
	int		x;
	double	wall_x;
	int		line_height;
	int		side;
}	t_draw_params;

#endif