/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:15:23 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:05:05 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

static void	missing_info(t_program *program, int dir_counter)
{
	if (dir_counter < 4)
		error_message(program, "Missing direction information\n");
	else if (program->ceilling_floor.f_color == -1)
		error_message(program, "Missing floor color information\n");
	else if (program->ceilling_floor.c_color == -1)
		error_message(program, "Missing ceiling color information\n");
}

static void	free_tmp(int *tmp)
{
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}

static int	is_rgb(t_program *program, char *line, int line_index)
{
	int	i;
	int	*tmp;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n' || !line[i])
		return (0);
	if (line[i] == 'F' && line[i + 1] == ' ')
	{
		tmp = check_colors(program, program->map.whole_file, line_index);
		program->ceilling_floor.f_color = rgb_to_int(tmp);
		free_tmp(tmp);
		return (1);
	}
	else if (line[i] == 'C' && line[i + 1] == ' ')
	{
		tmp = check_colors(program, program->map.whole_file, line_index);
		program->ceilling_floor.c_color = rgb_to_int(tmp);
		free_tmp(tmp);
		return (1);
	}
	return (0);
}

static int	begin_map_info(char *line)
{
	int		i;
	char	*str;

	str = ft_strtrim(line, " \t\n");
	i = 0;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!str[i])
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

void	check_first_info( t_program *program, int *i )
{
	int	dir_counter;
	int	j;

	dir_counter = 0;
	j = 0;
	while (program->map.whole_file[j]
		&& !begin_map_info(program->map.whole_file[j]))
	{
		if (is_rgb(program, program->map.whole_file[j], j))
		{
			j++;
			continue ;
		}
		check_abbrev(program, program->map.whole_file[j], &dir_counter);
		j++;
	}
	missing_info(program, dir_counter);
	*i = j;
}
