/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_of_perpendicular_ray.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:43:40 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3D.h"

void	calc_dist_of_perpendicular_ray(t_program *p, int side)
{
	if (side == 0)
		p->raycast.perp_wall_dist = (p->raycast.side_dist_x
				- p->raycast.delta_dist_x);
	else
		p->raycast.perp_wall_dist = (p->raycast.side_dist_y
				- p->raycast.delta_dist_y);
}
