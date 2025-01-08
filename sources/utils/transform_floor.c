/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:05:58 by jveras            #+#    #+#             */
/*   Updated: 2025/01/08 09:06:19 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	transform_floor(t_img_data *img, int color)
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
