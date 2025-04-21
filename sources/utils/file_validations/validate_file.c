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

#include "../../../includes/cube3d.h"

void	validate_file(t_program *program)
{

	int		i;
	char	**actual_map;
	
	i = 0;
	check_first_info(program, &i);

	actual_map = &program->map.map[i];

	check_for_invalid_characthers(program, actual_map);

	check_for_duplicates(program, actual_map);

	check_map_is_closed(program, actual_map);

	get_player_info(program, actual_map);

}
