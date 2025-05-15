/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:18:15 by jveras            #+#    #+#             */
/*   Updated: 2025/04/21 16:14:06 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

void	free_file(t_map *map)
{
	int	i;

	if (map->whole_file != NULL)
	{
		i = 0;
		while (map->whole_file[i] != NULL)
		{
			free(map->whole_file[i]);
			i++;
		}
		free(map->whole_file);
		map->whole_file = NULL;
	}
}
