/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_duplicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 03:22:55 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:06:24 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static int	check_remaining_positions(int *counts, int i)
{
	while (i < 4)
	{
		if (counts[i] > 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static void	check_equal_character_doubles(t_program *program,
	int *counts, int *i)
{
	while ((*i) < 4)
	{
		if (counts[*i] > 0)
		{
			if (counts[*i] > 1)
			{
				error_message(program,
					"Duplicated player start positions in map");
			}
			(*i)++;
			return ;
		}
		(*i)++;
	}
}

static void	check_for_duplicate_positions(t_program *program, int *counts)
{
	int	i;

	i = 0;
	check_equal_character_doubles(program, counts, &i);
	if (i == 4)
		error_message(program, "There is no player start position in map");
	else if (check_remaining_positions(counts, i))
		error_message(program, "Duplicated player start positions in map");
}

static void	initialize_counts(int *counts)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		counts[i] = 0;
		i++;
	}
}

void	check_for_duplicates(t_program *program, char **map)
{
	int	counts[4];
	int	i;
	int	j;

	initialize_counts(counts);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				counts[0]++;
			else if (map[i][j] == 'S')
				counts[1]++;
			else if (map[i][j] == 'E')
				counts[2]++;
			else if (map[i][j] == 'W')
				counts[3]++;
			j++;
		}
		i++;
	}
	check_for_duplicate_positions(program, counts);
}
