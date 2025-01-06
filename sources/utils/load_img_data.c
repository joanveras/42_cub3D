/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_and_wall_texture_data.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:00:06 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 21:13:05 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/cube3d.h"

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
	image->img_ptr = mlx_new_image(
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

void	load_texture_data(t_texture_data *texture)
{
	texture->data = mlx_get_data_addr(
		texture->tex_ptr,
		&texture->bpp,
		&texture->size_line,
		&texture->endian
	);
	if (!texture->data)
	{
		ft_putendl_fd(
			"Error! loading texture data: load_texture_data()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	load_texture(void *mlx, t_texture_data *texture,char *path)
{
	texture->tex_ptr = mlx_xpm_file_to_image(
		mlx,
		path,
		&texture->width,
		&texture->height
	);
	if (!texture->tex_ptr)
	{
		ft_putendl_fd(
			"Error! loading texture: load_texture()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
