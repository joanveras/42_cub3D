/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:26:48 by jveras            #+#    #+#             */
/*   Updated: 2025/01/08 09:35:32 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	wall_casting(t_program *program)
{
	int		x;
	int		side;
	int		lineHeight;
	double	wallX;

	transform_ceiling(&program->main_image, 0xDC6400);
	transform_floor(&program->main_image, 0xE11E00);
	
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		program->raycast.camera.x = 2 * x / (double)WINDOW_WIDTH - 1;
		program->raycast.rayDirX = program->player.viewDirX + program->raycast.camera.planeX * program->raycast.camera.x;
		program->raycast.rayDirY = program->player.viewDirY + program->raycast.camera.planeY * program->raycast.camera.x;

		program->map.x = (int)program->player.x;
		program->map.y = (int)program->player.y;

		program->raycast.deltaDistX = sqrt(1 + pow(program->raycast.rayDirY, 2) / pow(program->raycast.rayDirX, 2));
		program->raycast.deltaDistY = sqrt(1 + pow(program->raycast.rayDirX, 2) / pow(program->raycast.rayDirY, 2));

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
