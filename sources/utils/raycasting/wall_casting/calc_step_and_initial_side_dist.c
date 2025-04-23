/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_step_and_initial_side_dist.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:41:10 by jveras            #+#    #+#             */
/*   Updated: 2025/04/22 22:38:52 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	calc_step_and_initial_side_dist(t_program *program)
{
	program->map.x = (int)program->player.x;
	program->map.y = (int)program->player.y;

	if (program->raycast.rayDirX < 0)
	{
		program->map.step.x = -1;
		program->raycast.sideDistX = (program->player.x - program->map.x) * program->raycast.deltaDistX;
	}
	else
	{
		program->map.step.x = 1;
		program->raycast.sideDistX = (program->map.x + 1.0 - program->player.x) * program->raycast.deltaDistX;
	}
	if (program->raycast.rayDirY < 0)
	{
		program->map.step.y = -1;
		program->raycast.sideDistY = (program->player.y - program->map.y) * program->raycast.deltaDistY;
	}
	else
	{
		program->map.step.y = 1;
		program->raycast.sideDistY = (program->map.y + 1.0 - program->player.y) * program->raycast.deltaDistY;
	}
}
