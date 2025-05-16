/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:10:38 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"
#include "includes/libft.h"

static void	initialize_game(t_program *program, char *map_file)
{
	program->map.whole_file = open_file(map_file);
	validate_file(program);
	load_img(program->mlx, &program->main_image, WINDOW_WIDTH, WINDOW_HEIGHT);
	load_img_data(&program->main_image);
	bonus_load_textures(program);
}

static void	setup_hooks(t_program *program)
{
	mlx_hook(program->mlx_win, ON_KEYDOWN, KeyRelease,
		handle_key_inputs, program);
	mlx_hook(program->mlx_win, ON_DESTROY, NoEventMask,
		safe_exit, program);
	mlx_loop_hook(program->mlx, bonus_wall_casting, program);
}

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc != 2)
		return (ft_putstr_fd("Error: Invalid number of arguments\n", 2), 1);
	x11_connect(&program);
	initialize_game(&program, argv[1]);
	setup_hooks(&program);
	mlx_loop(program.mlx);
	return (0);
}
