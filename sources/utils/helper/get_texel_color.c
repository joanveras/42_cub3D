/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:17:31 by jveras            #+#    #+#             */
/*   Updated: 2025/03/12 15:16:08 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

int	get_color(t_texture_data tex, int texPosX, int texPosY)
{
	int	color;

	color = *(int *)(tex.data + (texPosY * tex.size_line + texPosX * (tex.bpp / 8)));
	return (color);
}

int get_texel_color(t_program *program, t_texture_data *tex, int texPosX, int texPosY)
{
	int		color;

	if (program->texture_index == 0)
		color = get_color(tex[0], texPosX, texPosY);
	else if (program->texture_index == 1)
		color = get_color(tex[1], texPosX, texPosY);
	else if (program->texture_index == 2)
		color = get_color(tex[2], texPosX, texPosY);
	else if (program->texture_index == 3)
		color = get_color(tex[3], texPosX, texPosY);

	return color;
}
