/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vertical_line_and_transform_image.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:46:19 by jveras            #+#    #+#             */
/*   Updated: 2025/01/05 10:24:03 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static int		calc_draw_start(int lineHeight)
{
	int	drawStart;

	drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	return (drawStart);
}

static int		calc_draw_end(int lineHeight)
{
	int	drawEnd;

	drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (drawEnd >= WINDOW_HEIGHT)
		drawEnd = WINDOW_HEIGHT - 1;
	return (drawEnd);
}

static int	calc_tex_pos_y(t_program *program, int y, int lineHeight)
{
	int	texPosY;

	texPosY = (int)((y - calc_draw_start(lineHeight)) * (double)program->wall_texture.height / lineHeight);
	return (texPosY);
}

void	calc_vertical_line_and_transform_image(t_program *program, int x, double wallX, int lineHeight, int side)
{
	int	drawEnd;
	int	texPosX;
	int	y;
	int	color;

	drawEnd = calc_draw_end(lineHeight);
	
	texPosX = (int)(wallX * program->wall_texture.width) % program->wall_texture.width;

	y = calc_draw_start(lineHeight);
	while (y < drawEnd)
	{
		color = get_texel_color(&program->wall_texture, texPosX, calc_tex_pos_y(program, y, lineHeight));
		if (side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(&program->floor_and_ceiling_img, x, y, color);
		y++;
	}
}
