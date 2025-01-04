/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_conditions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:04:51 by jveras            #+#    #+#             */
/*   Updated: 2025/01/04 00:07:51 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	w_conditions(t_program *program, int keycode)
{
	if (keycode == 'w' || keycode == 'W')
	{
		if (program->map.map[(int)(program->player.x + program->player.viewDirX * MOVE_SPEED)][(int)program->player.y] == '0')
			program->player.x += program->player.viewDirX * MOVE_SPEED;
		if (program->map.map[(int)program->player.x][(int)(program->player.y + program->player.viewDirY * MOVE_SPEED)] == '0')
			program->player.y += program->player.viewDirY * MOVE_SPEED;
	}
}
