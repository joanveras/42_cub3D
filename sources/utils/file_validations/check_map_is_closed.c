/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 04:18:11 by jveras            #+#    #+#             */
/*   Updated: 2025/04/21 05:04:43 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

static int	get_map_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static char	**copy_map(char **map)
{
	char	**copy;
	int		i;
	int		len;

	len = get_map_len(map);
	copy = malloc(sizeof(char *) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	free_map_copy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	is_invalid_cell(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	is_out_of_bounds(char **map, int x, int y)
{
	return (x < 0 || y < 0 || !map[x] || !map[x][y]);
}

static int	is_wall_or_filled(char c)
{
	return (c == '1' || c == 'F');
}

static int	is_exposed_to_outside(char **map, int x, int y)
{
	return ((x == 0 || y == 0 || !map[x + 1] || !map[x][y + 1])
		|| (map[x][y + 1] == ' ' || map[x][y - 1] == ' ')
		|| (map[x + 1] && map[x + 1][y] == ' ')
		|| (x > 0 && map[x - 1][y] == ' '));
}

static void	flood_fill(char **map, int x, int y, int *is_surrounded)
{
	if (is_invalid_cell(map[x][y])
		|| is_out_of_bounds(map, x, y)
		|| is_wall_or_filled(map[x][y]))
		return ;
	if (is_exposed_to_outside(map, x, y))
		*is_surrounded = 0;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y, is_surrounded);
	flood_fill(map, x - 1, y, is_surrounded);
	flood_fill(map, x, y + 1, is_surrounded);
	flood_fill(map, x, y - 1, is_surrounded);
}

static void	find_and_fill_zeros(char **map_copy, int *is_surrounded)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == '0')
			{
				flood_fill(map_copy, i, j, is_surrounded);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_map_is_closed(t_program *program, char **map)
{
	char	**map_copy;
	int		is_surrounded;

	map_copy = copy_map(map);
	if (!map_copy)
		error_message(program, "Error: failed to copy map for validation\n");
	is_surrounded = 1;
	find_and_fill_zeros(map_copy, &is_surrounded);
	free_map_copy(map_copy);
	if (!is_surrounded)
		error_message(program, "Error: map is not surrounded by walls\n");
}
