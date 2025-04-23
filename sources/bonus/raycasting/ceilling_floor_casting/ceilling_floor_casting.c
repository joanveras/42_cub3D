/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling_floor_casting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:07:03 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 03:12:02 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	ceiling_floor_casting(t_program *program)
{
	int			x;
	int			y;
	t_casting	casting;

	clear_image(&program->main_image, 0x000000);

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		calc_row_distance(program, &casting, y);

		casting.floorStepX = casting.rowDistance * (casting.rayDirX1 - casting.rayDirX0) / WINDOW_WIDTH;
		casting.floorStepY = casting.rowDistance * (casting.rayDirY1 - casting.rayDirY0) / WINDOW_WIDTH;

		casting.floorX = program->player.x + casting.rowDistance * casting.rayDirX0;
		casting.floorY = program->player.y + casting.rowDistance * casting.rayDirY0;

		x = 0;
		while (x < WINDOW_WIDTH)
		{
			calc_texel_point(&casting);

			casting.floorX += casting.floorStepX;
			casting.floorY += casting.floorStepY;

			if (y < WINDOW_HEIGHT/2);
				// transform_image_ceilling_side(program, &casting, x, y);
			else
				transform_image_floor_side(program, &casting, x, y);

			x++;
		}

		y++;
	}
}
