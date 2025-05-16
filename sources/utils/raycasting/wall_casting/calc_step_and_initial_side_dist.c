/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_step_and_initial_side_dist.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:41:10 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:54:59 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

static void	set_x_step_and_side(t_program *p)
{
	if (p->raycast.ray_dir_x < 0)
	{
		p->map.step.x = -1;
		p->raycast.side_dist_x = (p->player.x - p->map.x)
			* p->raycast.delta_dist_x;
	}
	else
	{
		p->map.step.x = 1;
		p->raycast.side_dist_x = (p->map.x + 1.0 - p->player.x)
			* p->raycast.delta_dist_x;
	}
}

static void	set_y_step_and_side(t_program *p)
{
	if (p->raycast.ray_dir_y < 0)
	{
		p->map.step.y = -1;
		p->raycast.side_dist_y = (p->player.y - p->map.y)
			* p->raycast.delta_dist_y;
	}
	else
	{
		p->map.step.y = 1;
		p->raycast.side_dist_y = (p->map.y + 1.0 - p->player.y)
			* p->raycast.delta_dist_y;
	}
}

void	calc_step_and_initial_side_dist(t_program *p)
{
	p->map.x = (int)p->player.x;
	p->map.y = (int)p->player.y;
	set_x_step_and_side(p);
	set_y_step_and_side(p);
}
