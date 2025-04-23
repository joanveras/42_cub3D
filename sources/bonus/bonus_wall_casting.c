/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wall_casting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:15:22 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 03:01:50 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	bonus_wall_casting(t_program *program)
{
	int		x;
	int		side;
	int		lineHeight;
	double	wallX;

	ceiling_floor_casting(program);

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		program->raycast.rayDirX = program->player.viewDirX + program->raycast.camera.planeX * (2 * x / (double)WINDOW_WIDTH - 1);
		program->raycast.rayDirY = program->player.viewDirY + program->raycast.camera.planeY * (2 * x / (double)WINDOW_WIDTH - 1);

		program->map.x = (int)program->player.x;
		program->map.y = (int)program->player.y;

		program->raycast.deltaDistX = fabs(1 / program->raycast.rayDirX);
		program->raycast.deltaDistY = fabs(1 / program->raycast.rayDirY);

		calc_step_and_initial_side_dist(program);

		perform_dda(program, &side);

		calc_dist_of_perpendicular_ray(program, side);

		lineHeight = (int)(WINDOW_HEIGHT / program->raycast.perpWallDist);
		
		calc_where_the_wall_was_hit(program, side, &wallX);
		
		calc_vertical_line_and_transform_image(program, x, wallX, lineHeight, side);
		
		x++;
	}

	mlx_put_image_to_window(program->mlx, program->mlx_win, program->main_image.img_ptr, 0, 0);

	return (0);
}
