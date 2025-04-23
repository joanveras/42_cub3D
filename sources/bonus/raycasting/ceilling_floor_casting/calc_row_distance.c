/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_row_distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:21:22 by jveras            #+#    #+#             */
/*   Updated: 2025/04/22 23:26:07 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	calc_row_distance(t_program *program, t_casting *casting, int y)
{
	casting->rayDirX0 = program->player.viewDirX - program->raycast.camera.planeX;
	casting->rayDirY0 = program->player.viewDirY - program->raycast.camera.planeY;
	casting->rayDirX1 = program->player.viewDirX + program->raycast.camera.planeX;
	casting->rayDirY1 = program->player.viewDirY + program->raycast.camera.planeY;

	casting->p = y - WINDOW_HEIGHT / 2;

	casting->posZ = 0.5 * WINDOW_HEIGHT;

	casting->rowDistance = casting->posZ / casting->p;
}
