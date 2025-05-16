/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:17:31 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	get_color(t_texture_data tex, int tex_pos_x, int tex_pos_y)
{
	int	color;
	int	offset;

	offset = tex_pos_y * tex.size_line + tex_pos_x * (tex.bpp / 8);
	color = *(int *)(tex.data + offset);
	return (color);
}

int	get_texel_color(t_program *program, t_texture_data *tex,
		int tex_pos_x, int tex_pos_y)
{
	int	color;

	color = 0;
	if (program->texture_index == 0)
		color = get_color(tex[0], tex_pos_x, tex_pos_y);
	else if (program->texture_index == 1)
		color = get_color(tex[1], tex_pos_x, tex_pos_y);
	else if (program->texture_index == 2)
		color = get_color(tex[2], tex_pos_x, tex_pos_y);
	else if (program->texture_index == 3)
		color = get_color(tex[3], tex_pos_x, tex_pos_y);
	return (color);
}
