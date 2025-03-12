/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:58:20 by jveras            #+#    #+#             */
/*   Updated: 2025/03/12 14:09:58 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static void	get_path(t_program *program, char c1, char c2, char *line)
{
	if (c1 == 'N' && c2 == 'O')
		program->textures.north = line;
	else if (c1 == 'S' && c2 == 'O')
		program->textures.south = line;
	else if (c1 == 'W' && c2 == 'E')
		program->textures.west = line;
	else if (c1 == 'E' && c2 == 'A')
		program->textures.east = line;
}

// First test for the initial './' characthers.
// If passes, then check if it has the extension '.xpm'
// And after, if it's a real file
void	check_path( t_program *program, char c1, char c2, char *line )
{
	int	i;

	i = 0;
	if (!line)
		error_message(INVALID_PATH);

	while (line[i] == ' ')
		i++;

	if (!line[i])
		error_message(INVALID_PATH);
	else if (line[i] == '.')
	{
		if (!line[i + 1])
			error_message(INVALID_PATH);
		else if (line[i + 1] == '/')
		{
			check_file_extension(&line[i + 2]);
			is_a_file(&line[i + 2]);
			get_path(program, c1, c2, &line[i + 2]);
			return ;
		}
		error_message(INVALID_PATH);
	}
}
