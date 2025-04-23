/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:58:30 by marcribe          #+#    #+#             */
/*   Updated: 2025/04/23 00:58:23 by jveras           ###   ########.fr       */
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
	int		p;
	int		cellX;
	int		cellY;
	int		tx;
	int		ty;
	float	rayDirX0;
	float	rayDirY0;
	float	rayDirX1;
	float	rayDirY1;
	float	posZ;
	float	rowDistance;
	float	floorStepX;
	float	floorStepY;
	float	floorX;
	float	floorY;
}	t_casting;

typedef	struct s_ceilling_floor
{
	int				c_color;
	int				f_color;
	t_casting		casting;
	t_texture_data	c_f_textures[2];
}	t_ceilling_floor;

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
	char	**whole_file;
	char	**map;
	int		x;
	int		y;
	t_step	step;
}	t_map;

typedef struct s_program
{
	void				*mlx;
	void				*mlx_win;
	int					texture_index;
	t_ceilling_floor	ceilling_floor;
	t_textures			textures;
	t_texture_data		wall_texture[4];
	t_img_data			main_image;
	t_player			player;
	t_raycasting		raycast;
	t_map				map;
}	t_program;

#endif
