/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_image_floor_side.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:33:16 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3D.h"

void	transform_image_floor_side(t_program *program, t_casting *casting,
			int x, int y)
{
	int	color;

	color = get_color(program->ceilling_floor.c_f_textures[1],
			casting->tx, casting->ty);
	put_pixel(&program->main_image, x, y, color);
}
