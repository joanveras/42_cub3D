/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:58:30 by marcribe          #+#    #+#             */
/*   Updated: 2025/05/15 18:54:06 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>

typedef enum e_hook_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_hook_events;

typedef struct s_texture_data
{
	void	*tex_ptr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
}	t_texture_data;

typedef struct s_casting
{
<<<<<<< HEAD
	int		p;
	int		cell_x;
	int		cell_y;
	int		tx;
	int		ty;
=======
	int		position;
	int		cell_x;
	int		cell_y;
	int		text_x;
	int		text_y;
>>>>>>> origin/jveras
	float	ray_dir_x0;
	float	ray_dir_y0;
	float	ray_dir_x1;
	float	ray_dir_y1;
	float	pos_z;
	float	row_distance;
	float	floor_step_x;
	float	floor_step_y;
	float	floor_x;
	float	floor_y;
}	t_casting;

<<<<<<< HEAD
typedef struct s_ceilling_floor
=======
typedef	struct s_ceiling_floor
>>>>>>> origin/jveras
{
	int				ceiling_color;
	int				floor_color;
	t_casting		casting;
	t_texture_data	ceiling_floor_textures[2];
}	t_ceiling_floor;

typedef struct s_textures
{
	char	*west;
	char	*east;
	char	*north;
	char	*south;
}	t_textures;

typedef struct s_img_data
{
	void	*img_ptr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
}	t_img_data;

typedef struct s_player
{
<<<<<<< HEAD
	double	x;
	double	y;
=======
	double	pos_x;
	double	pos_y;
>>>>>>> origin/jveras
	double	view_dir_x;
	double	view_dir_y;
}	t_player;

typedef struct s_camera
{
<<<<<<< HEAD
	double	x;
=======
>>>>>>> origin/jveras
	double	plane_x;
	double	plane_y;
}	t_camera;

typedef struct s_raycasting
{
	t_camera	camera;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
}	t_raycasting;

typedef struct s_step
{
	int	step_x;
	int	step_y;
}	t_step;

<<<<<<< HEAD
#endif
=======
typedef struct s_map
{
	char	**whole_file;
	char	**map;
	int		map_x;
	int		map_y;
	t_step	step;
}	t_map;

typedef struct s_program
{
	void				*mlx;
	void				*mlx_win;
	int					texture_index;
	t_ceiling_floor		ceiling_floor;
	t_textures			textures;
	t_texture_data		wall_texture[4];
	t_img_data			main_image;
	t_player			player;
	t_raycasting		raycast;
	t_map				map;
}	t_program;

#endif
>>>>>>> origin/jveras
