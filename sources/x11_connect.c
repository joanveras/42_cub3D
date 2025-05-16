/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x11_connect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:37:31 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:48:49 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	x11_connect(t_program *program)
{
	program->mlx = mlx_init();
	if (!program->mlx)
	{
		write(STDERR_FILENO, "Failed to connect to X11!", 21);
		exit(EXIT_FAILURE);
	}
	program->mlx_win = mlx_new_window(
			program->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			"Cube3D"
			);
	if (!program->mlx_win)
	{
		write(STDERR_FILENO, "Failed to open a window!", 21);
		exit(EXIT_FAILURE);
	}
}
