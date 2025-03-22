/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:58:30 by marcribe          #+#    #+#             */
/*   Updated: 2025/03/22 15:37:34 by jveras           ###   ########.fr       */
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

typedef struct s_floor_and_ceiling_colors
{
	uint64_t	floor_color;
	uint64_t	ceiling_color;
}	t_floor_and_ceiling_colors;

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
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img_data;

typedef struct s_texture_data
{
	void	*tex_ptr;
	int		width;
	int		height;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture_data;

typedef struct s_player
{
	double	x;
	double	y;
	double	viewDirX;
	double	viewDirY;
}	t_player;

typedef struct s_camera
{
	double	planeX;
	double	planeY;
}	t_camera;

typedef struct s_raycasting
{
	t_camera	camera;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
}	t_raycasting;

typedef struct s_step
{
	int	x;
	int	y;
}	t_step;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	t_step	step;
}	t_map;

typedef struct s_program
{
	void						*mlx;
	void						*mlx_win;
	int							texture_index;
	t_floor_and_ceiling_colors	f_c_colors;
	t_textures					textures;
	t_texture_data				wall_texture[4];
	t_img_data					main_image;
	t_player					player;
	t_raycasting				raycast;
	t_map						map;
}	t_program;

#endif
