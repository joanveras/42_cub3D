/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:08:34 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 22:11:19 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	backward(t_program *p, int key)
{
	double	new_x;
	double	new_y;

	if (key != 's' && key != 'S' && key != 65364)
		return ;
	new_x = p->player.x - p->player.view_dir_x * MOVE_SPEED;
	new_y = p->player.y - p->player.view_dir_y * MOVE_SPEED;
	if (p->map.map[(int)new_x][(int)p->player.y] == '0')
		p->player.x = new_x;
	if (p->map.map[(int)p->player.x][(int)new_y] == '0')
		p->player.y = new_y;
}
