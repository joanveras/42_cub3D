/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:18:15 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:30:58 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

void	free_file(t_map *map)
{
	int	i;

	if (!map->whole_file)
		return ;
	i = 0;
	while (map->whole_file[i])
		free(map->whole_file[i++]);
	free(map->whole_file);
	map->whole_file = NULL;
}
