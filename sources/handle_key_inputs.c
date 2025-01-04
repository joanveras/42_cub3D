/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:30:17 by jveras            #+#    #+#             */
/*   Updated: 2025/01/04 00:16:40 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	handle_key_inputs(int keycode, t_program *program)
{
	if (keycode == ESC)
		safe_exit(program);

	w_conditions(program, keycode);
	s_conditions(program, keycode);
	d_conditions(program, keycode);
	a_conditions(program, keycode);

	return (0);
}
