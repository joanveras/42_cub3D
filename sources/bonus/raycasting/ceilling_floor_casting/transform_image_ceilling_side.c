/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_image_ceilling_side.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:46:57 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 20:52:14 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	transform_image_ceilling_side(t_program *program, t_casting *casting,
			int x, int y)
{
	int	color;

	color = get_color(program->ceilling_floor.c_f_textures[0],
			casting->tx, casting->ty);
	put_pixel(&program->main_image, x, WINDOW_HEIGHT - y - 1, color);
}
