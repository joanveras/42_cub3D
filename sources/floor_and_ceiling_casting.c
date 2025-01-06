/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling_casting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:08:22 by jveras            #+#    #+#             */
/*   Updated: 2025/01/04 10:27:30 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	floor_and_ceiling_casting(t_program *program)
{
	int							x;
	int							y;
	t_floor_and_ceiling_casting	fc;

	clear_image(&program->floor_and_ceiling_img, 0x000000);

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		calc_row_distance(program, &fc, y);

		fc.floorStepX = fc.rowDistance * (fc.rayDirX1 - fc.rayDirX0) / WINDOW_WIDTH;
		fc.floorStepY = fc.rowDistance * (fc.rayDirY1 - fc.rayDirY0) / WINDOW_WIDTH;

		fc.floorX = program->player.x + fc.rowDistance * fc.rayDirX0;
		fc.floorY = program->player.y + fc.rowDistance * fc.rayDirY0;

		x = 0;
		while (x < WINDOW_WIDTH)
		{
			calc_texel_point(&fc);

			fc.floorX += fc.floorStepX;
			fc.floorY += fc.floorStepY;

			transform_image_floor_side(program, &fc, x, y);

			transform_image_ceiling_side(program, x, y);

			x++;
		}

		y++;
	}

	mlx_put_image_to_window(program->mlx, program->mlx_win, program->floor_and_ceiling_img.img_ptr, 0, 0);
}
