/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_where_the_wall_was_hit.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:44:48 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:45:54 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	calc_where_the_wall_was_hit(t_program *p, int side, double *wall_x)
{
	if (side == 0)
	{
		if (p->raycast.ray_dir_x > 0)
			p->texture_index = TEXTURE_EAST;
		else
			p->texture_index = TEXTURE_WEST;
		*wall_x = p->player.y + p->raycast.perp_wall_dist
			* p->raycast.ray_dir_y;
	}
	else
	{
		if (p->raycast.ray_dir_y > 0)
			p->texture_index = TEXTURE_SOUTH;
		else
			p->texture_index = TEXTURE_NORTH;
		*wall_x = p->player.x + p->raycast.perp_wall_dist
			* p->raycast.ray_dir_x;
	}
	*wall_x -= floor(*wall_x);
}
