/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:26:48 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3D.h"

static void	init_ray(t_program *p, int x)
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

static void	process_wall_column(t_program *p, int x, int *side)
{
	int		line_height;
	double	wall_x;

	calc_step_and_initial_side_dist(p);
	perform_dda(p, side);
	calc_dist_of_perpendicular_ray(p, *side);
	line_height = (int)(WINDOW_HEIGHT / p->raycast.perp_wall_dist);
	calc_where_the_wall_was_hit(p, *side, &wall_x);
	calc_vertical_line_and_transform_image(p, &(t_wall_params){
		.x = x,
		.wall_x = wall_x,
		.line_height = line_height,
		.side = *side
	});
}

int	wall_casting(t_program *p)
{
	int	x;
	int	side;

	transform_c_f(p);
	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		init_ray(p, x);
		process_wall_column(p, x, &side);
	}
	mlx_put_image_to_window(p->mlx, p->mlx_win, p->main_image.img_ptr, 0, 0);
	return (0);
}
