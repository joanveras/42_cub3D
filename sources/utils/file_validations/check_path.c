/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:58:20 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cub3D.h"

static void	get_path(t_program *program, char c1, char c2, char *line)
{
	if (c1 == 'N' && c2 == 'O')
		program->textures.north = ft_strtrim(line, " \t\n");
	else if (c1 == 'S' && c2 == 'O')
		program->textures.south = ft_strtrim(line, " \t\n");
	else if (c1 == 'W' && c2 == 'E')
		program->textures.west = ft_strtrim(line, " \t\n");
	else if (c1 == 'E' && c2 == 'A')
		program->textures.east = ft_strtrim(line, " \t\n");
}

void	check_path( t_program *program, char c1, char c2, char *line )
{
	int	i;

	i = 0;
	if (!line || line[i] == '\n')
		error_message(program, INVALID_PATH);
	while (line[i] == ' ')
		i++;
	if (!line || line[i] == '\n')
		error_message(program, INVALID_PATH);
	if (line[i] && line[i] != '\n')
	{
		check_file_extension(program, &line[i]);
		is_a_file(program, &line[i]);
		get_path(program, c1, c2, &line[i]);
		return ;
	}
	error_message(program, INVALID_PATH);
}
