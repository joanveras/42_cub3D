/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:59:55 by jveras            #+#    #+#             */
/*   Updated: 2025/01/08 11:02:32 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	load_textures(t_program *program)
{
	load_texture(program->mlx, &program->wall_texture[0], "assets/textures/bluestone.xpm");
	load_texture_data(&program->wall_texture[0]);
	load_texture(program->mlx, &program->wall_texture[1], "assets/textures/colorstone.xpm");
	load_texture_data(&program->wall_texture[1]);
	load_texture(program->mlx, &program->wall_texture[2], "assets/textures/eagle.xpm");
	load_texture_data(&program->wall_texture[2]);
	load_texture(program->mlx, &program->wall_texture[3], "assets/textures/greystone.xpm");
	load_texture_data(&program->wall_texture[3]);
	load_texture(program->mlx, &program->wall_texture[4], "assets/textures/mossy.xpm");
	load_texture_data(&program->wall_texture[4]);
	load_texture(program->mlx, &program->wall_texture[5], "assets/textures/purplestone.xpm");
	load_texture_data(&program->wall_texture[5]);
	load_texture(program->mlx, &program->wall_texture[6], "assets/textures/redbrick.xpm");
	load_texture_data(&program->wall_texture[6]);
	load_texture(program->mlx, &program->wall_texture[7], "assets/textures/wood.xpm");
	load_texture_data(&program->wall_texture[7]);
}
