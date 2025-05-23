/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_image_ceilling_side.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:46:57 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3D.h"

void	transform_image_ceilling_side(t_program *program, t_casting *casting,
			int x, int y)
{
	int	color;

	color = get_color(program->ceilling_floor.c_f_textures[0],
			casting->tx, casting->ty);
	put_pixel(&program->main_image, x, WINDOW_HEIGHT - y - 1, color);
}
