/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_texel_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:41:43 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 02:48:04 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	calc_texel_point(t_casting *casting)
{
	casting->cellX = (int)casting->floorX;
	casting->cellY = (int)casting->floorY;

	casting->text_x = (int)(textureWidth * (casting->floorX - casting->cellX)) & (textureWidth - 1);
	casting->text_y = (int)(textureHeight * (casting->floorY - casting->cellY)) & (textureHeight - 1);
}
