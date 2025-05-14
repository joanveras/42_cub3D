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

static int	invalid_characther(char C)
{
	if ((C != 'N' && C != 'S' && C != 'E' && C != 'W') &&
		(C != ' ' && C != '\t' && C != '\n') &&
		(C != '0' && C != '1'))
		return (1);
	return (0);
}

void	check_for_invalid_characthers(t_program *program, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (invalid_characther(map[i][j]))
			{
				error_message(program, "Invalid character in map");
			}
			j++;
		}
		i++;
	}
}
