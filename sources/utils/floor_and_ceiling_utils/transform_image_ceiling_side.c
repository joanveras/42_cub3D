/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_image_ceiling_side.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:55:20 by jveras            #+#    #+#             */
/*   Updated: 2025/01/04 00:02:38 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	transform_image_ceiling_side(t_program *program, t_floor_and_ceiling_casting *fc, int x, int y)
{
	int color;

	color = get_texel_color(&program->ceiling_texture, fc->tx, fc->ty);
	color = (color >> 1) & 8355711;
	put_pixel(&program->floor_and_ceiling_img, x, WINDOW_HEIGHT - y - 1, color);
}
