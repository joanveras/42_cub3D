/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conditions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:09:32 by jveras            #+#    #+#             */
/*   Updated: 2025/01/04 00:13:27 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	d_conditions(t_program *program, int keycode)
{
	double	oldViewDirX;
	double	oldPlaneX;

	if (keycode == 'd' || keycode == 'D')
	{
		oldViewDirX = program->player.viewDirX;
		program->player.viewDirX = program->player.viewDirX * cos(-ROT_SPEED) - program->player.viewDirY * sin(-ROT_SPEED);
		program->player.viewDirY = oldViewDirX * sin(-ROT_SPEED) + program->player.viewDirY * cos(-ROT_SPEED);

		oldPlaneX = program->raycast.camera.planeX;
		program->raycast.camera.planeX = program->raycast.camera.planeX * cos(-ROT_SPEED) - program->raycast.camera.planeY * sin(-ROT_SPEED);
		program->raycast.camera.planeY = oldPlaneX * sin(-ROT_SPEED) + program->raycast.camera.planeY * cos(-ROT_SPEED);
	}
}
