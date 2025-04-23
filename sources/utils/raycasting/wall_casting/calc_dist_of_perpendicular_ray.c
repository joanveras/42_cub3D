/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_of_perpendicular_ray.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:43:40 by jveras            #+#    #+#             */
/*   Updated: 2025/04/22 22:38:45 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	calc_dist_of_perpendicular_ray(t_program *program, int side)
{
	if (side == 0)
		program->raycast.perpWallDist = (program->raycast.sideDistX - program->raycast.deltaDistX);
	else
		program->raycast.perpWallDist = (program->raycast.sideDistY - program->raycast.deltaDistY);
}
