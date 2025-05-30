/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:41:51 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cub3D.h"

void	is_a_file(t_program *program, char *path)
{
	int	fd;

	path = ft_strtrim(path, " \t\n");
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		error_message(program, INVALID_PATH);
	}
	free(path);
	close(fd);
}
