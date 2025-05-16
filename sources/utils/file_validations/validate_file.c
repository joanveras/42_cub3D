/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:58:58 by marcribe          #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cub3D.h"

static void	init_crucial_variables(t_program *p)
{
	p->ceilling_floor.f_color = -1;
	p->ceilling_floor.c_color = -1;
	p->textures.north = NULL;
	p->textures.south = NULL;
	p->textures.east = NULL;
	p->textures.west = NULL;
}

void	validate_file(t_program *program)
{
	int	i;

	init_crucial_variables(program);
	i = 0;
	check_first_info(program, &i);
	program->map.map = &program->map.whole_file[i];
	check_for_invalid_characters(program, program->map.map);
	check_for_duplicates(program, program->map.map);
	check_map_is_closed(program, program->map.map);
	get_player_info(program, program->map.map);
}
