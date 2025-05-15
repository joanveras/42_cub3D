/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:13:19 by jveras            #+#    #+#             */
/*   Updated: 2025/04/21 02:37:24 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	left(t_program *program, int keycode)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode == 65 || keycode == 97)
	{
		old_dir_x = program->player.view_dir_x;
		program->player.view_dir_x = program->player.view_dir_x * cos(-ROT_SPEED) - program->player.view_dir_y * sin(-ROT_SPEED);
		program->player.view_dir_y = old_dir_x * sin(-ROT_SPEED) + program->player.view_dir_y * cos(-ROT_SPEED);
		old_plane_x = program->raycast.camera.plane_x;
		program->raycast.camera.plane_x = program->raycast.camera.plane_x * cos(-ROT_SPEED) - program->raycast.camera.plane_y * sin(-ROT_SPEED);
		program->raycast.camera.plane_y = old_plane_x * sin(-ROT_SPEED) + program->raycast.camera.plane_y * cos(-ROT_SPEED);
	}
}
