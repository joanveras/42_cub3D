/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_invalid_characthers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 03:25:28 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static int	invalid_character(char C)
{
	if ((C != 'N' && C != 'S' && C != 'E' && C != 'W')
		&& (C != ' ' && C != '\t' && C != '\n')
		&& (C != '0' && C != '1'))
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
			{
				error_message(program, "Invalid character in map");
			}
			j++;
		}
		i++;
	}
}
