/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_where_the_wall_was_hit.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:44:48 by jveras            #+#    #+#             */
/*   Updated: 2025/04/21 02:45:33 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

void	calc_where_the_wall_was_hit(t_program *program, int side, double *wallX)
{
	if (side == 0)
	{
		if (program->raycast.rayDirX > 0)
			program->texture_index = TEXTURE_EAST;
		else
			program->texture_index = TEXTURE_WEST;
		*wallX = program->player.y + program->raycast.perpWallDist * program->raycast.rayDirY;
	}
	else
	{
		if (program->raycast.rayDirY > 0)
			program->texture_index = TEXTURE_SOUTH;
		else
			program->texture_index = TEXTURE_NORTH;
		*wallX = program->player.x + program->raycast.perpWallDist * program->raycast.rayDirX;
	}
	*wallX -= floor(*wallX);
}
