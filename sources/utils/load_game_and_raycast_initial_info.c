/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_and_raycast_initial_info.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:55:26 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 20:56:39 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	load_game_and_raycast_initial_info(t_program *program)
{
	program->player.x = 19;
	program->player.y = 20;
	program->player.viewDirX = -1;
	program->player.viewDirY = 0;
	program->raycast.camera.planeX = 0;
	program->raycast.camera.planeY = 0.66;
}
