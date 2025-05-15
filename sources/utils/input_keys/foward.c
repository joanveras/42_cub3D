/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foward.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:04:51 by jveras            #+#    #+#             */
/*   Updated: 2025/02/20 14:23:13 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	foward(t_program *program, int keycode)
{
	if (keycode == 87 || keycode == 119)
	{
		if (program->map.map[(int)(program->player.pos_x + program->player.view_dir_x * MOVE_SPEED)][(int)program->player.pos_y] == '0')
			program->player.pos_x += program->player.view_dir_x * MOVE_SPEED;
		if (program->map.map[(int)program->player.pos_x][(int)(program->player.pos_y + program->player.view_dir_y * MOVE_SPEED)] == '0')
			program->player.pos_y += program->player.view_dir_y * MOVE_SPEED;
	}
}
