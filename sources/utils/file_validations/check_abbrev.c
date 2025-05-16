/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_abbrev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:06:07 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 20:47:52 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

static int	check_chars(t_program *p, char *l, int i, char c[2])
{
	if (l[i] == c[0] && l[i + 1] && (l[i + 1] == c[1] || l[i + 1] == ' '))
	{
		check_path(p, c[0], c[1], &l[i + 2]);
		return (1);
	}
	if (l[i] == c[0])
		error_message(p, "Invalid direction abbreviation\n");
	return (0);
}

void	check_abbrev(t_program *p, char *l, int *c)
{
	int		i;
	char	d[4][2];

	if (!l)
		return ;
	i = 0;
	while (l[i] == '\n' || l[i] == ' ')
		i++;
	ft_memcpy(d[0], "NO", 2);
	ft_memcpy(d[1], "SO", 2);
	ft_memcpy(d[2], "WE", 2);
	ft_memcpy(d[3], "EA", 2);
	while (l[i] && !(check_chars(p, l, i, d[0]) || check_chars(p, l, i, d[1])
			|| check_chars(p, l, i, d[2]) || check_chars(p, l, i, d[3])))
		i++;
	if (l[i])
		(*c)++;
}
