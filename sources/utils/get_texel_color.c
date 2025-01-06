/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:17:31 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 22:35:55 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int get_texel_color(t_texture_data *tex, int texPosX, int texPosY)
{
	char *dst = tex->data + (texPosY * tex->size_line + texPosX * (tex->bpp / 8));
	return *(unsigned int *)dst;
}
