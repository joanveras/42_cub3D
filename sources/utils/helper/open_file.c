/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:16:41 by jveras            #+#    #+#             */
/*   Updated: 2025/04/21 16:09:06 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"
#include "../../../includes/get_next_line.h"

static int	count_lines(char *path)
{
	int		fd;
	int		counter;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: could not open file\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

static void	fill_file(char *path, char **file)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		file[i] = ft_strdup(line);
		if (ft_strchr(file[i], '\n'))
			file[i][ft_strlen(file[i]) - 1] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	file[i] = NULL;
	close(fd);
}

char	**open_file(char *path)
{
	char	**file;

	file = malloc((count_lines(path) + 1) * sizeof(char *));
	if (!file)
	{
		ft_putstr_fd("Error: memory allocation failure\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fill_file(path, file);
	return (file);
}
