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

static char	**copy_map(char **map)
{
	char	**copy;
	int		i;
	int		len;

	i = 0;
	while (map[i])
		i++;
	len = i;
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

static void	flood_fill(char **map, int x, int y, int *is_surrounded)
{
	if ((map[x][y] == ' ' || map[x][y] == '\t' || map[x][y] == '\n') ||
		(x < 0 || y < 0 || !map[x] || !map[x][y]) ||
		(map[x][y] == '1' || map[x][y] == 'F'))
		return;

	if ((x == 0 || y == 0 || !map[x + 1] || !map[x][y + 1]) ||
		(map[x][y + 1] == ' ' || map[x][y - 1] == ' ') ||
		(map[x + 1] && map[x + 1][y] == ' ') ||
		(x > 0 && map[x - 1][y] == ' '))
		*is_surrounded = 0;

	map[x][y] = 'F';

	flood_fill(map, x + 1, y, is_surrounded);
	flood_fill(map, x - 1, y, is_surrounded);
	flood_fill(map, x, y + 1, is_surrounded);
	flood_fill(map, x, y - 1, is_surrounded);
}

void	check_map_is_closed(t_program *program, char **map)
{
	char	**map_copy;
	int		i;
	int		j;
	int		is_surrounded;
	
	map_copy = copy_map(map);
	if (!map_copy)
		error_message(program, "Failed to copy map for validation");
	
	is_surrounded = 1;
	i = 0;
	while (map_copy[i]) {
		j = 0;
		while (map_copy[i][j]) {
			if (map_copy[i][j] == '0') {
				flood_fill(map_copy, i, j, &is_surrounded);
				break;
			}
			j++;
		}
		if (!is_surrounded)
			break;
		i++;
	}
	free_map_copy(map_copy);
	if (!is_surrounded) {
		error_message(program, "Map is not surrounded by walls");
	}
}
