/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_row_distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:21:22 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:07:56 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	calc_row_distance(t_program *program, t_casting *casting, int y)
{
	casting->ray_dir_x0 = program->player.view_dir_x
		- program->raycast.camera.plane_x;
	casting->ray_dir_y0 = program->player.view_dir_y
		- program->raycast.camera.plane_y;
	casting->ray_dir_x1 = program->player.view_dir_x
		+ program->raycast.camera.plane_x;
	casting->ray_dir_y1 = program->player.view_dir_y
		+ program->raycast.camera.plane_y;
	casting->p = y - WINDOW_HEIGHT / 2;
	casting->pos_z = 0.5 * WINDOW_HEIGHT;
	casting->row_distance = casting->pos_z / casting->p;
}
