/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_load_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:20:56 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 03:31:01 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	bonus_load_textures(t_program *program)
{
	load_texture(program->mlx, &program->wall_texture[0], program->textures.west);
	load_texture_data(&program->wall_texture[0]);
	load_texture(program->mlx, &program->wall_texture[1], program->textures.east);
	load_texture_data(&program->wall_texture[1]);
	load_texture(program->mlx, &program->wall_texture[2], program->textures.north);
	load_texture_data(&program->wall_texture[2]);
	load_texture(program->mlx, &program->wall_texture[3], program->textures.south);
	load_texture_data(&program->wall_texture[3]);

	/*
	load_texture(program->mlx, &program->ceilling_floor.c_f_textures[0], "");
	load_texture_data(&program->ceilling_floor.c_f_textures[0]);
	*/
	load_texture(program->mlx, &program->ceilling_floor.c_f_textures[1], "assets/textures/grass_3.xpm");
	load_texture_data(&program->ceilling_floor.c_f_textures[1]);
}
