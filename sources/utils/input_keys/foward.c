/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foward.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:04:51 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 22:42:55 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	foward(t_program *program, int key)
{
	double	new_x;
	double	new_y;

	if (key != 'w' && key != 'W' && key != 65362)
		return ;
	new_x = program->player.x + program->player.view_dir_x * MOVE_SPEED;
	new_y = program->player.y + program->player.view_dir_y * MOVE_SPEED;
	if (program->map.map[(int)new_x][(int)program->player.y] == '0')
		program->player.x = new_x;
	if (program->map.map[(int)program->player.x][(int)new_y] == '0')
		program->player.y = new_y;
}
