/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:10:38 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 00:24:41 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc == 1)
		return (1);

	x11_connect(&program);

	program.map.whole_file = open_file(argv[1]);

	validate_file(&program);

	/* */
	load_img(program.mlx, &program.main_image, WINDOW_WIDTH, WINDOW_HEIGHT);
	load_img_data(&program.main_image);

	bonus_load_textures(&program);
	
	mlx_hook(program.mlx_win, ON_KEYDOWN, KeyRelease, handle_key_inputs, &program);
	mlx_hook(program.mlx_win, ON_DESTROY, NoEventMask, safe_exit, &program);

	mlx_loop_hook(program.mlx, bonus_wall_casting, &program);
	/* */
	
	mlx_loop(program.mlx);

	return (0);
}
