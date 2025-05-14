/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:49:58 by jveras            #+#    #+#             */
/*   Updated: 2025/04/21 16:38:16 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

static void	error_safe_exit(t_program *program)
{
	free_file(&program->map);
	free_textures_paths(program);
	mlx_destroy_window(program->mlx, program->mlx_win);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	exit(EXIT_SUCCESS);
}

void	error_message( t_program *program, const char *message )
{
	ft_putstr_fd((char *)message, STDERR_FILENO);
	error_safe_exit(program);
}
