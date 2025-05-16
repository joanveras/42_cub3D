/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling_floor_casting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:07:03 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:07:00 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

static void	calculate_floor_step(t_casting *cast)
{
	cast->floor_step_x = cast->row_distance
		* (cast->ray_dir_x1 - cast->ray_dir_x0) / WINDOW_WIDTH;
	cast->floor_step_y = cast->row_distance
		* (cast->ray_dir_y1 - cast->ray_dir_y0) / WINDOW_WIDTH;
}

static void	init_floor_ray(t_program *p, t_casting *cast, int y)
{
	calc_row_distance(p, cast, y);
	calculate_floor_step(cast);
	cast->floor_x = p->player.x + cast->row_distance * cast->ray_dir_x0;
	cast->floor_y = p->player.y + cast->row_distance * cast->ray_dir_y0;
}

static void	process_floor_pixel(t_program *p, t_casting *cast, int x, int y)
{
	calc_texel_point(cast);
	if (y >= WINDOW_HEIGHT / 2)
		transform_image_floor_side(p, cast, x, y);
	cast->floor_x += cast->floor_step_x;
	cast->floor_y += cast->floor_step_y;
}

void	ceiling_floor_casting(t_program *p)
{
	t_casting	cast;
	int			x;
	int			y;

	clear_image(&p->main_image, 0x000000);
	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		init_floor_ray(p, &cast, y);
		x = -1;
		while (++x < WINDOW_WIDTH)
			process_floor_pixel(p, &cast, x, y);
	}
}
