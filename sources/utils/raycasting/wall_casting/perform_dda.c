/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:42:16 by jveras            #+#    #+#             */
/*   Updated: 2025/04/22 22:38:30 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	perform_dda(t_program *program, int *side)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (program->raycast.side_dist_x < program->raycast.side_dist_y)
		{
			program->raycast.side_dist_x += program->raycast.delta_dist_x;
			program->map.map_x += program->map.step.step_x;
			*side = 0;
		}
		else
		{
			program->raycast.side_dist_y += program->raycast.delta_dist_y;
			program->map.map_y += program->map.step.step_y;
			*side = 1;
		}
		if (program->map.map[program->map.map_x][program->map.map_y] == '1')
			hit = 1;
	}
}
