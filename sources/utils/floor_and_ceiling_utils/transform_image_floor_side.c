/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_image_floor_side.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:49:45 by jveras            #+#    #+#             */
/*   Updated: 2025/01/05 10:21:31 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	transform_image_floor_side(t_program *program, t_floor_and_ceiling_casting *fc, int x, int y)
{
	int color;

	color = get_texel_color(&program->floor_texture, fc->tx, fc->ty);
	color = (color >> 1) & 8355711;
	put_pixel(&program->floor_and_ceiling_img, x, y, color);
}
