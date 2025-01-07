/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_floor_and_ceiling_data.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:44:18 by jveras            #+#    #+#             */
/*   Updated: 2025/01/07 18:49:54 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	load_floor_data(t_program *program, char *path)
{
	load_texture(program->mlx, &program->floor_texture, path);
	load_texture_data(&program->floor_texture);
}

/*
static void	load_ceiling_data(t_program *program, char *path)
{
	load_texture(program->mlx, &program->ceiling_texture, path);
	load_texture_data(&program->ceiling_texture);
}
*/

void	load_floor_and_ceiling_data(t_program *program)
{
	load_img(program->mlx, &program->floor_and_ceiling_img, WINDOW_WIDTH, WINDOW_HEIGHT);
	load_img_data(&program->floor_and_ceiling_img);
	load_floor_data(program, "assets/textures/colorstone.xpm");
}
