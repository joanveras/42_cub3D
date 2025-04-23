/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:32:08 by jveras            #+#    #+#             */
/*   Updated: 2025/04/21 16:37:37 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

static void remain_something(t_program *program,
	char *str, char *line, int *tmp)
{
	str = ft_strtrim(str, " \t\n");
	if (str[0])
	{
		free(str);
		free(tmp);
		free(line);
		error_message(program, INVALID_COLOR_FORMAT);
	}
	free(str);
	free(line);
}

static void	set_rgb(int *r, int *g, int *b,
	const char *str, int index)
{
	if (index == 0)
		*r = ft_atoi(str);
	else if (index == 1)
		*g = ft_atoi(str);
	else if (index == 2)
		*b = ft_atoi(str);
}

static int	is_next_char_a_digit(t_program *program, const char *str)
{
	int	i;

	if (!str)
		return (0);

	i = 0;
	while (ft_isdigit(str[i]))
		i++;

	if (i == 0 || i > 3)
		error_message(program, INVALID_COLOR_FORMAT);

	return (i);

}

static void	validate_rgb_format(t_program *program, char *line, int *ret)
{
	int	i, j, k;

	char	*str;

	i = 0;
	if (!line || line[i] == ',')
		error_message(program, INVALID_COLOR_FORMAT);

	str = line;

	while (i < 3)
	{
		j = 0;
		if (str[j] == ',')
			j++;

		while (str[j] == ' ')
			j++;

		str = str + j;

		k = is_next_char_a_digit(program, str);

		set_rgb(&ret[0], &ret[1], &ret[2], str, i);

		str = str + k;

		j = 0;
		while (str[j] == ' ')
			j++;

		str = str + j;

		i++;
	}

	remain_something(program, str, line, ret);

}

int	*check_colors(t_program *program, char **map, int i)
{

	int	k;
	int	*ret;

	ret = malloc(sizeof(int) * 3);

	k = 0;
	while (map[i][k] == ' ')
		k++;

	validate_rgb_format(program, ft_strtrim(&map[i][k + 1], " \t\n"), ret);

	return (ret);

}
