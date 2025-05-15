/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_image_ceiling_side.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:46:57 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 02:54:57 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	transform_image_ceiling_side(t_program *program, t_casting *casting, int x, int y)
{
	int color;

	color = get_color(program->ceiling_floor.ceiling_floor_textures[0], casting->text_x, casting->text_y);
	put_pixel(&program->main_image, x, WINDOW_HEIGHT - y - 1, color);
}
