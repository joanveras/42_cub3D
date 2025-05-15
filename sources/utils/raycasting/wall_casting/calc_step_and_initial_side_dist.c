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
	if (program->raycast.ray_dir_x < 0)
	{
		program->map.step.step_x = -1;
		program->raycast.side_dist_x = (program->player.pos_x - program->map.map_x)
			* program->raycast.delta_dist_x;
	}
	else
	{
		program->map.step.step_x = 1;
		program->raycast.side_dist_x = (program->map.map_x + 1.0 - program->player.pos_x)
			* program->raycast.delta_dist_x;
	}
	if (program->raycast.ray_dir_y < 0)
	{
		program->map.step.step_y = -1;
		program->raycast.side_dist_y = (program->player.pos_y - program->map.map_y)
			* program->raycast.delta_dist_y;
	}
	else
	{
		program->map.step.step_y = 1;
		program->raycast.side_dist_y = (program->map.map_y + 1.0 - program->player.pos_y)
			* program->raycast.delta_dist_y;
	}
	program->map.map_x = (int)program->player.pos_x;
	program->map.map_y = (int)program->player.pos_y;
}
