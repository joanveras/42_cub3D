/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/05/15 21:24:34 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

static void	init_crucial_variables(t_program *p)
{
	p->ceilling_floor.f_color = -1;
	p->ceilling_floor.c_color = -1;
	p->textures.north = NULL;
	p->textures.south = NULL;
	p->textures.east = NULL;
	p->textures.west = NULL;
}

static void	perform_map_checks(t_program *p, int i)
{
	p->map.map = &p->map.whole_file[i];
	check_for_invalid_characters(p, p->map.map);
	check_for_duplicates(p, p->map.map);
	check_map_is_closed(p, p->map.map);
	get_player_info(p, p->map.map);
}

void	validate_file(t_program *program)
{
	int	i;

	init_crucial_variables(program);
	i = 0;
	check_first_info(program, &i);
	program->map.map = &program->map.whole_file[i];
	check_for_invalid_characthers(program, program->map.map);
	check_for_duplicates(program, program->map.map);
	check_map_is_closed(program, program->map.map);
	get_player_info(program, program->map.map);
}
