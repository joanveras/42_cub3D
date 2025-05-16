/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:13:19 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:36:59 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	left(t_program *p, int key)
{
	double	old_dir;
	double	old_plane;

	if (key != 'a' && key != 'A' && key != 65361)
		return ;
	old_dir = p->player.viewDirX;
	p->player.viewDirX = old_dir * cos(-ROT_SPEED)
		- p->player.viewDirY * sin(-ROT_SPEED);
	p->player.viewDirY = old_dir * sin(-ROT_SPEED)
		+ p->player.viewDirY * cos(-ROT_SPEED);
	old_plane = p->raycast.camera.planeX;
	p->raycast.camera.planeX = old_plane * cos(-ROT_SPEED)
		- p->raycast.camera.planeY * sin(-ROT_SPEED);
	p->raycast.camera.planeY = old_plane * sin(-ROT_SPEED)
		+ p->raycast.camera.planeY * cos(-ROT_SPEED);
}
