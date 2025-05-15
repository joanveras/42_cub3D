/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:53:34 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:14:14 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

static void	init_crucial_variables(t_program *program)
{
	program->ceiling_floor.floor_color = -1;
	program->ceiling_floor.ceiling_color = -1;
	program->textures.north = NULL;
	program->textures.south = NULL;
	program->textures.east = NULL;
	program->textures.west = NULL;
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
