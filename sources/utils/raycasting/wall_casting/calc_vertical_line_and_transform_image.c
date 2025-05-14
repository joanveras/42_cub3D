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

static int	calc_draw_start(int lineHeight)
{
	int	drawStart;

	drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	return (drawStart);
}

static int	calc_draw_end(int lineHeight)
{
	int	drawEnd;

	drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (drawEnd >= WINDOW_HEIGHT)
		drawEnd = WINDOW_HEIGHT - 1;
	return (drawEnd);
}

static int	calc_tex_pos_y(int y, int lineHeight)
{
	int	d;
	int	texPosY;

	d = y * 256 - WINDOW_HEIGHT * 128 + lineHeight * 128;

	texPosY = ((d * textureHeight) / lineHeight) / 256;

	return (texPosY);
}

void	calc_vertical_line_and_transform_image(t_program *program, int x, double wallX, int lineHeight, int side)
{
	int	drawEnd;
	int	texPosX;
	int	y;
	int	color;

	drawEnd = calc_draw_end(lineHeight);

	texPosX = (int)(wallX * textureWidth) % textureWidth;

	y = calc_draw_start(lineHeight);
	while (y < drawEnd)
	{
		color = get_texel_color(program, program->wall_texture, texPosX, calc_tex_pos_y(y, lineHeight));
		if (side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(&program->main_image, x, y, color);
		y++;
	}
}
