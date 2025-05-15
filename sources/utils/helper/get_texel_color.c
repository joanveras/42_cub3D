/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:17:31 by jveras            #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2025/05/14 20:33:58 by jveras           ###   ########.fr       */
=======
/*   Updated: 2025/05/14 19:02:20 by jveras           ###   ########.fr       */
>>>>>>> origin/main
=======
/*   Updated: 2025/03/22 16:06:47 by jveras           ###   ########.fr       */
>>>>>>> origin/jveras
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static int	get_color(t_texture_data tex, int tex_x, int tex_y)
{
	int	color;

	color = *(int *)(tex.data + (tex_y * tex.size_line
				+ tex_x * (tex.bpp / 8)));
	return (color);
}

int	get_texel_color(t_program *program, t_texture_data *tex,
		int tex_x, int tex_y)
{
	int	color;

	if (program->texture_index == 0)
		color = get_color(tex[0], tex_x, tex_y);
	else if (program->texture_index == 1)
		color = get_color(tex[1], tex_x, tex_y);
	else if (program->texture_index == 2)
		color = get_color(tex[2], tex_x, tex_y);
	else if (program->texture_index == 3)
		color = get_color(tex[3], tex_x, tex_y);
	return (color);
}
