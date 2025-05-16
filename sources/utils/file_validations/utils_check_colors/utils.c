/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:53:16 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 20:54:45 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cube3d.h"

void	clean_and_error(t_program *p, char *s, char *l, int *r)
{
	free(s);
	free(r);
	free(l);
	error_message(p, INVALID_COLOR_FORMAT);
}

void	remain_something(t_program *p, char *s, char *l, int *r)
{
	s = ft_strtrim(s, " \t\n");
	if (s[0])
		clean_and_error(p, s, l, r);
	free(s);
	free(l);
}

void	set_rgb(int *rgb, const char *s, int i)
{
	if (i == 0)
		rgb[0] = ft_atoi(s);
	else if (i == 1)
		rgb[1] = ft_atoi(s);
	else if (i == 2)
		rgb[2] = ft_atoi(s);
}

int	is_next_digit(t_program *p, const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	if (i == 0 || i > 3)
		error_message(p, INVALID_COLOR_FORMAT);
	return (i);
}
