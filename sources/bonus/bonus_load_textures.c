/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_load_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:20:56 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	load_wall_textures(t_program *program, int index, char *path)
{
	load_texture(program->mlx, &program->wall_texture[index], path);
	load_texture_data(&program->wall_texture[index]);
}

void	bonus_load_textures(t_program *program)
{
	load_wall_textures(program, 0, program->textures.west);
	load_wall_textures(program, 1, program->textures.east);
	load_wall_textures(program, 2, program->textures.north);
	load_wall_textures(program, 3, program->textures.south);
	load_texture(program->mlx, &program->ceilling_floor.c_f_textures[1],
		FLOOR_TEXTURE);
	load_texture_data(&program->ceilling_floor.c_f_textures[1]);
}
