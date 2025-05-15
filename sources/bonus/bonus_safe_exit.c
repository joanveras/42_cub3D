/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_safe_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:25:42 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 19:21:29 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	free_c_f_textures(t_texture_data c_f_textures[2], void *mlx)
{
	int i = 0;
	while (i < 2)
	{
		if (c_f_textures[i].tex_ptr != NULL)
		{
			mlx_destroy_image(mlx, c_f_textures[i].tex_ptr);
			c_f_textures[i].tex_ptr = NULL;
		}
		i++;
	}
}

static void	free_wall_textures(t_texture_data wall_texture[4], void *mlx)
{
	int i = 0;
	while (i < 4)
	{
		if (wall_texture[i].tex_ptr != NULL)
		{
			mlx_destroy_image(mlx, wall_texture[i].tex_ptr);
			wall_texture[i].tex_ptr = NULL;
		}
		i++;
	}
}

static void	free_main_image(t_img_data *main_image, void *mlx)
{
	if (main_image->img_ptr != NULL)
	{
		mlx_destroy_image(mlx, main_image->img_ptr);
		main_image->img_ptr = NULL;
	}
}

int	bonus_safe_exit(t_program *program)
{
	free_c_f_textures(program->ceilling_floor.c_f_textures, program->mlx);
	free_wall_textures(program->wall_texture, program->mlx);
	free_main_image(&program->main_image, program->mlx);
	free_textures_paths(program);
	free_file(&program->map);
	mlx_destroy_window(program->mlx, program->mlx_win);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
