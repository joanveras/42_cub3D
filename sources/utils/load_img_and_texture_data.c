/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_and_texture_data.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:00:06 by jveras            #+#    #+#             */
/*   Updated: 2024/12/30 21:13:05 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/cube3d.h"

void	load_img_data(t_program *program)
{
	program->image.data = mlx_get_data_addr(
		program->image.img_ptr,
		&program->image.bpp,
		&program->image.size_line,
		&program->image.endian
	);
	if (!program->image.data)
	{
		ft_putendl_fd(
			"Error! Loading image data: load_img_data()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	load_img(t_program *program)
{
	program->image.img_ptr = mlx_new_image(
		program->mlx,
		WINDOW_WIDTH,
		WINDOW_HEIGHT
	);
	if (!program->image.img_ptr)
	{
		ft_putendl_fd("Error! loading image: load_img()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	load_texture_data(t_program *program)
{
	program->texture.data = mlx_get_data_addr(
		program->texture.tex_ptr,
		&program->texture.bpp,
		&program->texture.size_line,
		&program->texture.endian
	);
	if (!program->texture.data)
	{
		ft_putendl_fd(
			"Error! loading texture data: load_texture_data()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	load_texture(t_program *program, char *path)
{
	program->texture.tex_ptr = mlx_xpm_file_to_image(
		program->mlx,
		path,
		&program->texture.width,
		&program->texture.height
	);
	if (!program->texture.tex_ptr)
	{
		ft_putendl_fd(
			"Error! loading texture: load_texture()", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	load_all_images(t_program *program, char *path)
{
	load_img(program);
	load_img_data(program);
	if (!path)
		load_texture(program, "assets/textures/redbrick.xpm");
	else
		load_texture(program, path);
	load_texture_data(program);
}
