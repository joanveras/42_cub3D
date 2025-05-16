/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:30:17 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	handle_key_inputs(int keycode, t_program *program)
{
	if (keycode == ESC)
		safe_exit(program);
	if (keycode == KEY_W)
		foward(program, keycode);
	if (keycode == KEY_S)
		backward(program, keycode);
	if (keycode == KEY_D)
		right(program, keycode);
	if (keycode == KEY_A)
		left(program, keycode);
	return (0);
}
