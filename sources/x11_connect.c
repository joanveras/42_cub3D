/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x11_connect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:37:31 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
			"cub3D"
			);
	if (!program->mlx_win)
	{
		write(STDERR_FILENO, "Failed to open a window!", 21);
		exit(EXIT_FAILURE);
	}
}
