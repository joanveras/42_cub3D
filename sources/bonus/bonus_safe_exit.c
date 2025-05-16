/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_safe_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:25:42 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	free_texture_array(t_texture_data *textures,
				void *mlx, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (textures[i].tex_ptr)
		{
			mlx_destroy_image(mlx, textures[i].tex_ptr);
			textures[i].tex_ptr = NULL;
		}
	}
}

static void	free_mlx_resources(t_program *p)
{
	free_texture_array(p->ceilling_floor.c_f_textures, p->mlx, 2);
	free_texture_array(p->wall_texture, p->mlx, 4);
	if (p->main_image.img_ptr)
		mlx_destroy_image(p->mlx, p->main_image.img_ptr);
	if (p->mlx_win)
		mlx_destroy_window(p->mlx, p->mlx_win);
	if (p->mlx)
	{
		mlx_destroy_display(p->mlx);
		free(p->mlx);
	}
}

int	bonus_safe_exit(t_program *program)
{
	free_mlx_resources(program);
	free_textures_paths(program);
	free_file(&program->map);
	exit(EXIT_SUCCESS);
	return (0);
}
