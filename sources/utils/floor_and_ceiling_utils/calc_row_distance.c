/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_row_distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:28:48 by jveras            #+#    #+#             */
/*   Updated: 2025/01/03 23:44:17 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	calc_row_distance(t_program *program, t_floor_and_ceiling_casting *fc, int y)
{
	fc->rayDirX0 = program->player.viewDirX - program->raycast.camera.planeX;
	fc->rayDirY0 = program->player.viewDirY - program->raycast.camera.planeY;
	fc->rayDirX1 = program->player.viewDirX + program->raycast.camera.planeX;
	fc->rayDirY1 = program->player.viewDirY + program->raycast.camera.planeY;

	fc->p = y - WINDOW_HEIGHT / 2;

	fc->posZ = 0.5 * WINDOW_HEIGHT;

	fc->rowDistance = fc->posZ / fc->p;
}
