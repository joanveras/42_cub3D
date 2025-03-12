/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:59:55 by jveras            #+#    #+#             */
/*   Updated: 2025/03/12 15:17:00 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

void	load_textures(t_program *program)
{
	load_texture(program->mlx, &program->wall_texture[0], program->textures.west);
	load_texture_data(&program->wall_texture[0]);
	load_texture(program->mlx, &program->wall_texture[1], program->textures.east);
	load_texture_data(&program->wall_texture[1]);
	load_texture(program->mlx, &program->wall_texture[2], program->textures.north);
	load_texture_data(&program->wall_texture[2]);
	load_texture(program->mlx, &program->wall_texture[3], program->textures.south);
	load_texture_data(&program->wall_texture[3]);
}
