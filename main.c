/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:01:17 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 20:57:26 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc == 1)
		return (1);

	x11_connect(&program);

	program.map.map = open_map(argv[1]);

	load_all_images(&program, NULL);

	load_game_and_raycast_initial_info(&program);
	
	mlx_hook(program.mlx_win, ON_KEYDOWN, KeyRelease, handle_key_inputs, &program);
	mlx_hook(program.mlx_win, ON_DESTROY, 0L, safe_exit, &program);

	mlx_loop_hook(program.mlx, raycasting, &program);
	
	mlx_loop(program.mlx);

	return (0);
}
