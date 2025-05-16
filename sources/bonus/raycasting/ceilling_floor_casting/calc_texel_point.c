/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_texel_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:41:43 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:07:40 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	calc_texel_point(t_casting *casting)
{
	casting->cell_x = (int)(casting->floor_x);
	casting->cell_y = (int)(casting->floor_y);
	casting->tx = (int)(TEXTURE_WIDTH * (casting->floor_x - casting->cell_x))
		& (TEXTURE_WIDTH - 1);
	casting->ty = (int)(TEXTURE_HEIGHT * (casting->floor_y - casting->cell_y))
		& (TEXTURE_HEIGHT - 1);
}
