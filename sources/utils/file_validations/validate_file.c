/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:53:34 by jveras            #+#    #+#             */
/*   Updated: 2025/03/26 19:14:14 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"
#include "../../../includes/structs.h"

void	validate_file(t_program *program)
{

	int	i;
	
	i = 0;
	check_first_info(program, &i);

	printf("\n");
	printf("%d\n", i + 1);
	printf("%s\n", program->map.map[i]);

	// ...

}
