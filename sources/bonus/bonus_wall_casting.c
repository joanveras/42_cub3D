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

static void	init_ray_dir(t_program *program, int x)
{
	program->raycast.ray_dir_x = program->player.view_dir_x
		+ program->raycast.camera.plane_x * (2 * x / (double)WINDOW_WIDTH - 1);
	program->raycast.ray_dir_y = program->player.view_dir_y
		+ program->raycast.camera.plane_y * (2 * x / (double)WINDOW_WIDTH - 1);
	program->map.x = (int)program->player.pos_x;
	program->map.y = (int)program->player.pos_y;
	program->raycast.delta_dist_x = fabs(1 / program->raycast.ray_dir_x);
	program->raycast.delta_dist_y = fabs(1 / program->raycast.ray_dir_y);
}

static void	cast_single_ray(t_program *program, int x)
{
	int		side;
	int		line_height;
	double	wall_x;

	init_ray_dir(program, x);
	calc_step_and_initial_side_dist(program);
	perform_dda(program, &side);
	calc_dist_of_perpendicular_ray(program, side);
	line_height = (int)(WINDOW_HEIGHT / program->raycast.perp_wall_dist);
	calc_where_the_wall_was_hit(program, side, &wall_x);
	calc_vertical_line_and_transform_image(program, x, wall_x, line_height, side);
}

int	bonus_wall_casting(t_program *program)
{
	int	x;

	ceiling_floor_casting(program);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		cast_single_ray(program, x);
		x++;
	}
	mlx_put_image_to_window(program->mlx, program->mlx_win,
		program->main_image.img_ptr, 0, 0);
	return (0);
}
