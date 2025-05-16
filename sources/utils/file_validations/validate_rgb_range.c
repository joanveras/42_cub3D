/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rgb_range.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:27:15 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:14:30 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

void	validate_rgb_range(t_program *program, int *rgb)
{
	if (rgb[0] < 0 || rgb[0] > 255)
	{
		free(rgb);
		error_message(program, INVALID_RGB_RANGE);
	}
	if (rgb[1] < 0 || rgb[1] > 255)
	{
		free(rgb);
		error_message(program, INVALID_RGB_RANGE);
	}
	if (rgb[2] < 0 || rgb[2] > 255)
	{
		free(rgb);
		error_message(program, INVALID_RGB_RANGE);
	}
}
