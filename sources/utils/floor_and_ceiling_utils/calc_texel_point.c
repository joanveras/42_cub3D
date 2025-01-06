/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_texel_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:38:24 by jveras            #+#    #+#             */
/*   Updated: 2025/01/03 23:41:35 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	calc_texel_point(t_floor_and_ceiling_casting *fc)
{
	fc->cellX = (int)fc->floorX;
	fc->cellY = (int)fc->floorY;

	fc->tx = (int)(textureWidth * (fc->floorX - fc->cellX)) & (textureWidth - 1);
	fc->ty = (int)(textureHeight * (fc->floorY - fc->cellY)) & (textureHeight - 1);
}
