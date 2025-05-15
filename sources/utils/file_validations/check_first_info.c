/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:15:23 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 01:54:33 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"



static int	process_floor_color(t_program *program, char **map, int line_index)
{
	int	*tmp;

	tmp = check_colors(program, map, line_index);
	program->ceiling_floor.floor_color = rgb_to_int(tmp);
	free_tmp(tmp);
	return (1);
}

static int	process_ceiling_color(t_program *program, char **map, int line_index)
{
	int	*tmp;

	tmp = check_colors(program, map, line_index);
	program->ceiling_floor.ceiling_color = rgb_to_int(tmp);
	free_tmp(tmp);
	return (1);
}

static int	is_rgb(t_program *program, char *line, int line_index)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n' || !line[i])
		return (0);
	if (line[i] == 'F' && line[i + 1] == ' ')
		return (process_floor_color(program, program->map.whole_file,
				line_index));
	else if (line[i] == 'C' && line[i + 1] == ' ')
		return (process_ceiling_color(program, program->map.whole_file,
				line_index));
	return (0);
}



void	check_first_info(t_program *program, int *i)
{
	int	dir_counter;
	int	j;

	dir_counter = 0;
	j = 0;
	while (program->map.whole_file[j] && !begin_map_info(program->map.whole_file[j]))
	{
		if (is_rgb(program, program->map.whole_file[j], j))
		{
			j++;
			continue;
		}
		check_abbrev(program, program->map.whole_file[j], &dir_counter);
		j++;
	}
	missing_info(program, dir_counter);
	*i = j;
}
