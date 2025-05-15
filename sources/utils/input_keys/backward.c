/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:08:34 by jveras            #+#    #+#             */
/*   Updated: 2025/02/20 14:23:06 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	backward(t_program *program, int keycode)
{
	if (keycode == 83 || keycode == 115)
	{
		if (program->map.map[(int)(program->player.pos_x - program->player.view_dir_x * MOVE_SPEED)][(int)program->player.pos_y] == '0')
			program->player.pos_x -= program->player.view_dir_x * MOVE_SPEED;
		if (program->map.map[(int)program->player.pos_x][(int)(program->player.pos_y - program->player.view_dir_y * MOVE_SPEED)] == '0')
			program->player.pos_y -= program->player.view_dir_y * MOVE_SPEED;
	}
} 