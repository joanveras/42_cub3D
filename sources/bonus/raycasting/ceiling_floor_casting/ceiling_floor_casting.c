/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor_casting.c                           :+:      :+:    :+:   */
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

		casting.floor_step_x = casting.row_distance * (casting.ray_dir_x1 - casting.ray_dir_x0) / WINDOW_WIDTH;
		casting.floor_step_y = casting.row_distance * (casting.ray_dir_y1 - casting.ray_dir_y0) / WINDOW_WIDTH;

		casting.floor_x = program->player.pos_x + casting.row_distance * casting.ray_dir_x0;
		casting.floor_y = program->player.pos_y + casting.row_distance * casting.ray_dir_y0;

		x = 0;
		while (x < WINDOW_WIDTH)
		{
			calc_texel_point(&casting);

			casting.floor_x += casting.floor_step_x;
			casting.floor_y += casting.floor_step_y;

			if (y < WINDOW_HEIGHT/2);
				// transform_image_ceiling_side(program, &casting, x, y);
			else
				transform_image_floor_side(program, &casting, x, y);

			x++;
		}

		y++;
	}
}
