/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:00:06 by jveras            #+#    #+#             */
/*   Updated: 2025/05/16 16:53:25 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cub3D.h"

void	load_img_data(t_img_data *image)
{
	image->data = mlx_get_data_addr(
			image->img_ptr,
			&image->bpp,
			&image->size_line,
			&image->endian
			);
	if (!image->data)
	{
		ft_putendl_fd(
			"Error! Loading image data: load_img_data()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	load_img(void *mlx, t_img_data *image, int width, int height)
{
	image->img_ptr = mlx_new_image
		(
			mlx,
			width,
			height
			);
	if (!image->img_ptr)
	{
		ft_putendl_fd("Error! creating image: load_img()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
