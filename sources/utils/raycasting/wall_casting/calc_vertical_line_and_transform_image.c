/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vertical_line_and_transform_image.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:46:19 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 01:33:10 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

static int	calc_draw_start(int line_height)
{
	int	draw_start;

	draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

static int	calc_draw_end(int line_height)
{
	int	draw_end;

	draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	return (draw_end);
}

static int	calc_tex_pos_y(int y, int line_height)
{
	int	d;
	int	tex_pos_y;

	d = y * 256 - WINDOW_HEIGHT * 128 + line_height * 128;
	tex_pos_y = ((d * textureHeight) / line_height) / 256;
	return (tex_pos_y);
}

void	calc_vertical_line_and_transform_image(t_program *program,
			int x, double wall_x, int line_height, int side)
{
	int	draw_end;
	int	tex_pos_x;
	int	y;
	int	color;

	draw_end = calc_draw_end(line_height);
	tex_pos_x = (int)(wall_x * textureWidth) % textureWidth;
	y = calc_draw_start(line_height);
	while (y < draw_end)
	{
		color = get_texel_color(program, program->wall_texture,
				tex_pos_x, calc_tex_pos_y(y, line_height));
		if (side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(&program->main_image, x, y, color);
		y++;
	}
}
