/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:32:08 by jveras            #+#    #+#             */
/*   Updated: 2025/04/23 18:43:04 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

void	skip_spaces_and_comma(char **str)
{
	int	j;

	j = 0;
	if ((*str)[j] == ',')
		j++;
	while ((*str)[j] == ' ')
		j++;
	*str = *str + j;
}

void	set_rgb_value(int *ret, const char *str, int index)
{
	if (index == 0)
		ret[0] = ft_atoi(str);
	else if (index == 1)
		ret[1] = ft_atoi(str);
	else if (index == 2)
		ret[2] = ft_atoi(str);
}

int	is_next_char_a_digit(t_program *program, const char *str)
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