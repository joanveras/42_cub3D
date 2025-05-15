/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_load_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:20:56 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 16:19:43 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	load_wall_textures(t_program *program)
{
	load_texture(program->mlx, &program->wall_texture[0], program->textures.west);
	load_texture_data(&program->wall_texture[0]);
	load_texture(program->mlx, &program->wall_texture[1], program->textures.east);
	load_texture_data(&program->wall_texture[1]);
	load_texture(program->mlx, &program->wall_texture[2],
		program->textures.north);
	load_texture_data(&program->wall_texture[2]);
	load_texture(program->mlx, &program->wall_texture[3],
		program->textures.south);
	load_texture_data(&program->wall_texture[3]);
}

void	bonus_load_textures(t_program *program)
{
	load_wall_textures(program);
	load_texture(program->mlx, &program->ceiling_floor.ceiling_floor_textures[1],
		FLOOR_TEXTURE);
	load_texture_data(&program->ceiling_floor.ceiling_floor_textures[1]);
}
