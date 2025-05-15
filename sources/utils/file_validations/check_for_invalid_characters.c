/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_invalid_characthers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 03:25:28 by jveras            #+#    #+#             */
/*   Updated: 2025/04/21 05:00:12 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static int	invalid_character(char c)
{
	if ((c != 'N' && c != 'S' && c != 'E' && c != 'W') &&
		(c != ' ' && c != '\t' && c != '\n') &&
		(c != '0' && c != '1'))
		return (1);
	return (0);
}

void	check_for_invalid_characters(t_program *program, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (invalid_character(map[i][j]))
				error_message(program, "Error: invalid character in map\n");
			j++;
		}
		i++;
	}
}
