/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:27:51 by jveras            #+#    #+#             */
/*   Updated: 2025/03/12 15:16:43 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"
#include "../../../includes/cube3d.h"

void	load_texture_data(t_texture_data *texture)
{
	texture->data = mlx_get_data_addr(texture->tex_ptr, &texture->bpp,
			&texture->size_line, &texture->endian);
	if (!texture->data)
	{
		ft_putendl_fd("Error: failed to load texture data", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	load_texture(void *mlx, t_texture_data *texture, char *path)
{
	texture->tex_ptr = mlx_xpm_file_to_image(mlx, path,
			&texture->width, &texture->height);
	if (!texture->tex_ptr)
	{
		ft_putendl_fd("Error: failed to load texture", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
