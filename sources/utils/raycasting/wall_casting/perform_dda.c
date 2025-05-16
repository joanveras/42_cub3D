/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:42:16 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 22:22:04 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	perform_dda(t_program *program, int *side)
{
	while (1)
	{
		if (program->raycast.side_dist_x < program->raycast.side_dist_y)
		{
			program->raycast.side_dist_x += program->raycast.delta_dist_x;
			program->map.x += program->map.step.x;
			*side = 0;
		}
		else
		{
			program->raycast.side_dist_y += program->raycast.delta_dist_y;
			program->map.y += program->map.step.y;
			*side = 1;
		}
		if ((program->map.map[program->map.x][program->map.y] - '0') > 0)
			break ;
	}
}
