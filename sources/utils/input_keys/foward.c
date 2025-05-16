/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foward.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:04:51 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:32:13 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	forward(t_program *p, int key)
{
	double	new_x;
	double	new_y;

	if (key != 'w' && key != 'W' && key != 65362)
		return ;
	new_x = p->player.x + p->player.viewDirX * MOVE_SPEED;
	new_y = p->player.y + p->player.viewDirY * MOVE_SPEED;
	if (p->map.map[(int)new_x][(int)p->player.y] == '0')
		p->player.x = new_x;
	if (p->map.map[(int)p->player.x][(int)new_y] == '0')
		p->player.y = new_y;
}
