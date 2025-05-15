/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_info_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:15:23 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 01:54:33 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

void	missing_info(t_program *program, int dir_counter)
{
	if (dir_counter < 4)
		error_message(program, "Missing direction information\n");
	else if (program->ceiling_floor.floor_color == -1)
		error_message(program, "Missing floor color information\n");
	else if (program->ceiling_floor.ceiling_color == -1)
		error_message(program, "Missing ceiling color information\n");
}

void	free_tmp(int *tmp)
{
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}

int	is_empty_line(const char *str)
{
	return (!str[0]);
}

int	is_all_digits(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (!str[i]);
}

int	begin_map_info(char *line)
{
	int		result;
	char	*str;

	str = ft_strtrim(line, " \t\n");
	if (is_empty_line(str))
	{
		free(str);
		return (0);
	}
	result = is_all_digits(str);
	free(str);
	return (result);
} 