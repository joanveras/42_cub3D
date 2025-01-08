/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:17:31 by jveras            #+#    #+#             */
/*   Updated: 2025/01/08 10:52:58 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	get_color(t_texture_data tex, int texPosX, int texPosY)
{
	int	color;

	color = *(int *)(tex.data + (texPosY * tex.size_line + texPosX * (tex.bpp / 8)));
	return (color);
}

int get_texel_color(t_program *program, t_texture_data *tex, int texPosX, int texPosY)
{
	int		x;
	int		y;
	int		color;

	x = program->map.x;
	y = program->map.y;
	if (program->map.map[x][y] - '0' == 1)
		color = get_color(tex[0], texPosX, texPosY);
	else if (program->map.map[x][y] - '0' == 2)
		color = get_color(tex[1], texPosX, texPosY);
	else if (program->map.map[x][y] - '0' == 3)
		color = get_color(tex[2], texPosX, texPosY);
	else if (program->map.map[x][y] - '0' == 4)
		color = get_color(tex[3], texPosX, texPosY);
	else if (program->map.map[x][y] - '0' == 5)
		color = get_color(tex[4], texPosX, texPosY);
	else if (program->map.map[x][y] - '0' == 6)
		color = get_color(tex[5], texPosX, texPosY);
	else if (program->map.map[x][y] - '0' == 7)
		color = get_color(tex[6], texPosX, texPosY);

	return color;
}