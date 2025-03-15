/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:30:17 by jveras            #+#    #+#             */
/*   Updated: 2025/03/01 01:00:59 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	handle_key_inputs(int keycode, t_program *program)
{
	if (keycode == ESC)
		safe_exit(program);

	foward(program, keycode);

	backward(program, keycode);

	right(program, keycode);
	
	left(program, keycode);

	return (0);
}
