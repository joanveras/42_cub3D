/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:59:55 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static void	load_wall_texture(t_program *p, int index, char *path)
{
	load_texture(p->mlx, &p->wall_texture[index], path);
	load_texture_data(&p->wall_texture[index]);
}

void	load_textures(t_program *p)
{
	load_wall_texture(p, 0, p->textures.west);
	load_wall_texture(p, 1, p->textures.east);
	load_wall_texture(p, 2, p->textures.north);
	load_wall_texture(p, 3, p->textures.south);
}
