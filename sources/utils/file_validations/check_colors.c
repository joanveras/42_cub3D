/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:32:08 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 18:43:04 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

static void	remain_something(t_program *program, char *str,
		char *line, int *ret)
{
	str = ft_strtrim(str, " \t\n");
	if (str[0])
	{
		free(str);
		free(ret);
		free(line);
		error_message(program, INVALID_COLOR_FORMAT);
	}
	free(str);
	free(line);
}



static void	process_rgb_value(t_program *program, char **str,
		int *ret, int index)
{
	int	k;

	skip_spaces_and_comma(str);
	k = is_next_char_a_digit(program, *str);
	set_rgb_value(ret, *str, index);
	*str = *str + k;
	skip_spaces_and_comma(str);
}

static void	validate_rgb_format(t_program *program, char *line, int *ret)
{
	int		i;
	char	*str;

	i = 0;
	if (!line || line[i] == ',')
		error_message(program, INVALID_COLOR_FORMAT);
	str = line;
	while (i < 3)
	{
		process_rgb_value(program, &str, ret, i);
		i++;
	}
	remain_something(program, str, line, ret);
}

int	*check_colors(t_program *program, char **map, int i)
{
	int	k;
	int	*ret;

	ret = malloc(sizeof(int) * 3);
	ret[0] = -1;
	ret[1] = -1;
	ret[2] = -1;
	k = 0;
	while (map[i][k] == ' ')
		k++;
	validate_rgb_format(program, ft_strtrim(&map[i][k + 1], " \t\n"), ret);
	validate_rgb_range(program, ret);
	return (ret);
}
