/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vertical_line_and_transform_image.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:46:19 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:54:31 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

typedef struct s_wall_params {
	int		x;
	double	wall_x;
	int		line_height;
	int		side;
}	t_wall_params;

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
	tex_pos_y = ((d * TEXTURE_HEIGHT) / line_height) / 256;
	return (tex_pos_y);
}

void	calc_vertical_line_and_transform_image(t_program *p,
t_wall_params *params)
{
	int	y;
	int	draw_end;
	int	tex_pos_x;
	int	color;

	draw_end = calc_draw_end(params->line_height);
	tex_pos_x = (int)(params->wall_x * TEXTURE_WIDTH) % TEXTURE_WIDTH;
	y = calc_draw_start(params->line_height);
	while (y < draw_end)
	{
		color = get_texel_color(p, p->wall_texture, tex_pos_x,
				calc_tex_pos_y(y, params->line_height));
		if (params->side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(&p->main_image, params->x, y, color);
		y++;
	}
}
