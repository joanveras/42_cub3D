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

void	validate_file(t_program *program)
{

	int	i;
	
	i = 0;
	check_first_info(program, &i);

	program->map.map = &program->map.whole_file[i];

	check_for_invalid_characthers(program, program->map.map);

	check_for_duplicates(program, program->map.map);

	check_map_is_closed(program, program->map.map);

	get_player_info(program, program->map.map);

}
