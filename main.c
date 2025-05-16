/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:01:17 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 20:59:55 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc != 2)
		return (1);
	x11_connect(&program);
	program.map.whole_file = open_file(argv[1]);
	validate_file(&program);
	load_img(program.mlx, &program.main_image,
		WINDOW_WIDTH, WINDOW_HEIGHT);
	load_img_data(&program.main_image);
	load_textures(&program);
	mlx_hook(program.mlx_win, 2, 1L << 0, handle_key_inputs, &program);
	mlx_hook(program.mlx_win, 17, 0, safe_exit, &program);
	mlx_loop_hook(program.mlx, wall_casting, &program);
	mlx_loop(program.mlx);
	return (0);
}
