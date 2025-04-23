/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_c_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:45:28 by jveras            #+#    #+#             */
/*   Updated: 2025/04/22 23:04:40 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static void	transform_ceiling(t_img_data *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

static void	transform_floor(t_img_data *img, int color)
{
	int	x;
	int	y;

	y = WINDOW_HEIGHT / 2;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	transform_c_f(t_program *program)
{
	transform_ceiling(&program->main_image, program->ceilling_floor.c_color);
	transform_floor(&program->main_image, program->ceilling_floor.f_color);
}
