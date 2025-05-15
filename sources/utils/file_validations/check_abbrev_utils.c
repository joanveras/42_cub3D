/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_abbrev_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:06:07 by jveras            #+#    #+#             */
/*   Updated: 2025/04/19 22:24:39 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

int	check_characters(t_program *program, char *line, char c1, char c2)
{
	if (line[0] == c1)
	{
		if (line[1] && (line[1] == c2 || line[1] == ' '))
		{
			check_path(program, c1, c2, &line[2]);
			return (1);
		}
		error_message(program, "Error: invalid direction abbreviation\n");
	}
	return (0);
} 