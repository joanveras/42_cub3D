/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:32:08 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/libft.h"
#include "../../../../includes/cub3D.h"

static void	validate_rgb_format(t_program *p, char *l, int *r)
{
	int		i[3];
	char	*s;

	i[0] = 0;
	if (!l || l[i[0]] == ',')
		error_message(p, INVALID_COLOR_FORMAT);
	s = l;
	while (i[0] < 3)
	{
		i[1] = 0;
		if (s[i[1]] == ',')
			i[1]++;
		while (s[i[1]] == ' ')
			i[1]++;
		s += i[1];
		i[2] = is_next_digit(p, s);
		set_rgb(r, s, i[0]);
		s += i[2];
		i[1] = 0;
		while (s[i[1]] == ' ')
			i[1]++;
		s += i[1];
		i[0]++;
	}
	remain_something(p, s, l, r);
}

int	*check_colors(t_program *p, char **map, int i)
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
	validate_rgb_format(p, ft_strtrim(&map[i][k + 1], " \t\n"), ret);
	validate_rgb_range(p, ret);
	return (ret);
}
