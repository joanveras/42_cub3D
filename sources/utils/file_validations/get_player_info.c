/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:13:47 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static void	save_player_pos(t_program *program, int x, int y)
{
	program->player.x = x + 0.5;
	program->player.y = y + 0.5;
	program->map.map[x][y] = '0';
}

static void	save_view_dir(t_program *program, double dirX, double dirY)
{
	program->player.view_dir_x = dirX;
	program->player.view_dir_y = dirY;
}

static void	save_perp_planes(t_program *program, double planeX, double planeY)
{
	program->raycast.camera.plane_x = planeX;
	program->raycast.camera.plane_y = planeY;
}

// The view direction must be perpendicular to the planes!
static void	save_player_info(t_program *program, char **map, int x, int y)
{
	if (map[x][y] == 'N')
	{
		save_player_pos(program, x, y);
		save_view_dir(program, 0, -1);
		save_perp_planes(program, 0.66, 0);
	}
	else if (map[x][y] == 'S')
	{
		save_player_pos(program, x, y);
		save_view_dir(program, 0, 1);
		save_perp_planes(program, -0.66, 0);
	}
	else if (map[x][y] == 'W')
	{
		save_player_pos(program, x, y);
		save_view_dir(program, -1, 0);
		save_perp_planes(program, 0, -0.66);
	}
	else if (map[x][y] == 'E')
	{
		save_player_pos(program, x, y);
		save_view_dir(program, 1, 0);
		save_perp_planes(program, 0, 0.66);
	}
}

void	get_player_info(t_program *program, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			save_player_info(program, map, x, y);
			y++;
		}
		x++;
	}
}
