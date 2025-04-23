/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:09:46 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 00:36:02 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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

int	safe_exit(t_program *program)
{
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
