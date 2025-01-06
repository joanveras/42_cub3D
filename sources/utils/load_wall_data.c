/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wall_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 08:26:12 by jveras            #+#    #+#             */
/*   Updated: 2025/01/03 09:26:54 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"
#include "../../includes/structs.h"

void	load_wall_data(t_program *program, char *path)
{
	load_texture(program->mlx, &program->wall_texture, path);
	load_texture_data(&program->wall_texture);
}
