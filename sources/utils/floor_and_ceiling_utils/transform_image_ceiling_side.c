/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_image_ceiling_side.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:55:20 by jveras            #+#    #+#             */
/*   Updated: 2025/01/04 10:26:27 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	transform_image_ceiling_side(t_program *program, int x, int y)
{
	int color;
	
	color = (173 << 16) | (216 << 8) | 230;
	put_pixel(&program->floor_and_ceiling_img, x, WINDOW_HEIGHT - y - 1, color);
}
