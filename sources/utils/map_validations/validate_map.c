/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:53:34 by jveras            #+#    #+#             */
/*   Updated: 2025/03/12 15:02:16 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	validate_map(t_program *program)
{

	int		i;
	int		*tmp;
	char	*str;
	
	i = 0;
	check_directions(program, &i);

	tmp = check_colors(program->map.map, &i);
	program->f_c_colors.floor_color = rgb_to_int(tmp);
	// free tmp

	tmp = check_colors(program->map.map, &i);
	program->f_c_colors.ceiling_color = rgb_to_int(tmp);
	// free tmp

	printf("\n");
	printf("%d\n", i + 1);
	printf("%s\n", program->map.map[i]);

	// ...

}
