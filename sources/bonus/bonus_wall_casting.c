/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wall_casting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:15:22 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 23:19:10 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	init_raycast(t_program *p, int x)
{
	p->raycast.ray_dir_x = p->player.view_dir_x + p->raycast.camera.plane_x
		* (2 * x / (double)WINDOW_WIDTH - 1);
	p->raycast.ray_dir_y = p->player.view_dir_y + p->raycast.camera.plane_y
		* (2 * x / (double)WINDOW_WIDTH - 1);
	p->map.x = (int)p->player.x;
	p->map.y = (int)p->player.y;
	p->raycast.delta_dist_x = fabs(1 / p->raycast.ray_dir_x);
	p->raycast.delta_dist_y = fabs(1 / p->raycast.ray_dir_y);
}

static void	process_wall_column(t_program *p, int x)
{
	int		side;
	int		line_height;
	double	wall_x;

	calc_step_and_initial_side_dist(p);
	perform_dda(p, &side);
	calc_dist_of_perpendicular_ray(p, side);
	line_height = (int)(WINDOW_HEIGHT / p->raycast.perp_wall_dist);
	calc_where_the_wall_was_hit(p, side, &wall_x);
	calc_vertical_line_and_transform_image(p, &(t_wall_params){
		.x = x,
		.wall_x = wall_x,
		.line_height = line_height,
		.side = side
	});
}

int	bonus_wall_casting(t_program *program)
{
	int	x;

	ceiling_floor_casting(program);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_raycast(program, x);
		process_wall_column(program, x);
		x++;
	}
	mlx_put_image_to_window(program->mlx, program->mlx_win,
		program->main_image.img_ptr, 0, 0);
	return (0);
}
