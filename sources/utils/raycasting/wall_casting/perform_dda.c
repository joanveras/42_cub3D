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
	while (1)
	{
		if (program->raycast.sideDistX < program->raycast.sideDistY)
		{
			program->raycast.sideDistX += program->raycast.deltaDistX;
			program->map.x += program->map.step.x;
			*side = 0;
		}
		else
		{
			program->raycast.sideDistY += program->raycast.deltaDistY;
			program->map.y += program->map.step.y;
			*side = 1;
		}
		if ((program->map.map[program->map.x][program->map.y] - '0') > 0)
			break ;
	}
}
