/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vertical_line_and_transform_image.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:46:19 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 22:49:19 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static int		calc_draw_start(int lineHeight)
{
	int	drawStart;

	drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2 + 100;
	if (drawStart < 0)
		drawStart = 0;
	return (drawStart);
}

static int		calc_draw_end(int lineHeight)
{
	int	drawEnd;

	drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2 + 100;
	if (drawEnd >= WINDOW_HEIGHT)
		drawEnd = WINDOW_HEIGHT - 1;
	return (drawEnd);
}

static int	calc_tex_pos_y(t_program *program, int y, int lineHeight)
{
	int	texPosY;

	texPosY = (int)((y - calc_draw_start(lineHeight)) * (double)program->texture.height / lineHeight);
	return (texPosY);
}

void	calc_vertical_line_and_transform_image(t_program *program, int x, double wallX, int lineHeight)
{
	int	drawEnd;
	int	texPosX;
	int	y;
	int	color;

	drawEnd = calc_draw_end(lineHeight);
	
	texPosX = (int)(wallX * program->texture.width) % program->texture.width;

	y = calc_draw_start(lineHeight);
	while (y < drawEnd)
	{
		color = get_texel_color(&program->texture, texPosX, calc_tex_pos_y(program, y, lineHeight));
		put_pixel(&program->image, x, y, color);
		y++;
	}
}
