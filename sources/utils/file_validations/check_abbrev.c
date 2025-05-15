/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_abbrev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:06:07 by jveras            #+#    #+#             */
/*   Updated: 2025/04/19 22:24:39 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

static int	check_direction(t_program *program, char *line, int *dir_counter)
{
	if (check_characters(program, line, 'N', 'O')
		|| check_characters(program, line, 'S', 'O')
		|| check_characters(program, line, 'W', 'E')
		|| check_characters(program, line, 'E', 'A'))
	{
		(*dir_counter)++;
		return (1);
	}
	return (0);
}

void	check_abbrev(t_program *program, char *line, int *dir_counter)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i] == '\n')
		i++;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		if (check_direction(program, &line[i], dir_counter))
			break ;
		i++;
	}
}
