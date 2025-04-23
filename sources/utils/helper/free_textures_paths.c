/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:35:37 by jveras            #+#    #+#             */
/*   Updated: 2025/04/21 16:35:51 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

void	free_textures_paths(t_program *program)
{
	free(program->textures.north);
	free(program->textures.south);
	free(program->textures.east);
	free(program->textures.west);
}
