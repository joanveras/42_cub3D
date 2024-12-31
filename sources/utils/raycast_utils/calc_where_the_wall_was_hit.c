/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_where_the_wall_was_hit.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:44:48 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 22:49:42 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

void	calc_where_the_wall_was_hit(t_program *program, int side, double *wallX)
{
	if (side == 0)
		*wallX = program->player.y + program->raycast.perpWallDist * program->raycast.rayDirY;
	else
		*wallX = program->player.x + program->raycast.perpWallDist * program->raycast.rayDirX;
	*wallX -= floor(*wallX);
}
