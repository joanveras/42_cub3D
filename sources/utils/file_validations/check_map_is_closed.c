/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 04:18:11 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cub3D.h"

static char	**copy_map(char **m)
{
	char	**cpy;
	int		i;
	int		l;

	i = -1;
	l = 0;
	while (m[l])
		l++;
	cpy = malloc(sizeof(char *) * (l + 1));
	if (!cpy)
		return (NULL);
	while (++i < l)
	{
		cpy[i] = ft_strdup(m[i]);
		if (!cpy[i])
		{
			while (--i >= 0)
				free(cpy[i]);
			free(cpy);
			return (NULL);
		}
	}
	cpy[i] = NULL;
	return (cpy);
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
	if ((map[x][y] == ' ' || map[x][y] == '\t' || map[x][y] == '\n')
		|| (x < 0 || y < 0 || !map[x] || !map[x][y])
		|| (map[x][y] == '1' || map[x][y] == 'F'))
		return ;
	if ((x == 0 || y == 0 || !map[x + 1] || !map[x][y + 1])
		|| (map[x][y + 1] == ' ' || map[x][y - 1] == ' ')
		|| (map[x + 1] && map[x + 1][y] == ' ')
		|| (x > 0 && map[x - 1][y] == ' '))
		*is_surrounded = 0;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y, is_surrounded);
	flood_fill(map, x - 1, y, is_surrounded);
	flood_fill(map, x, y + 1, is_surrounded);
	flood_fill(map, x, y - 1, is_surrounded);
}

void	check_map_is_closed(t_program *p, char **m)
{
	char	**cpy;
	int		i[3];

	cpy = copy_map(m);
	i[2] = 1;
	if (!cpy)
		error_message(p, "Failed to copy map");
	i[0] = -1;
	while (cpy[++i[0]] && i[2])
	{
		i[1] = -1;
		while (cpy[i[0]][++i[1]] && i[2])
			if (cpy[i[0]][i[1]] == '0')
				flood_fill(cpy, i[0], i[1], &i[2]);
	}
	free_map_copy(cpy);
	if (!i[2])
		error_message(p, "Map not surrounded by walls");
}
