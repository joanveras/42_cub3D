/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_where_the_wall_was_hit.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:44:48 by jveras            #+#    #+#             */
/*   Updated: 2025/04/22 22:38:50 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	calc_where_the_wall_was_hit(t_program *program, int side, double *wallX)
{
	if (side == 0)
	{
		if (program->raycast.ray_dir_x > 0)
			program->texture_index = TEXTURE_EAST;
		else
			program->texture_index = TEXTURE_WEST;
		*wallX = program->player.pos_y + program->raycast.perp_wall_dist * program->raycast.ray_dir_y;
	}
	else
	{
		if (program->raycast.ray_dir_y > 0)
			program->texture_index = TEXTURE_SOUTH;
		else
			program->texture_index = TEXTURE_NORTH;
		*wallX = program->player.pos_x + program->raycast.perp_wall_dist * program->raycast.ray_dir_x;
	}
	*wallX -= floor(*wallX);
}
