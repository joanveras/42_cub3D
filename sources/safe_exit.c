/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcribe <marcribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:09:46 by jveras            #+#    #+#             */
/*   Updated: 2025/05/15 21:24:29 by marcribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	free_textures(t_texture_data *textures, int count, void *mlx)
{
	int	i;

	i = -1;
	while (++i < count)
		if (textures[i].tex_ptr)
			mlx_destroy_image(mlx, textures[i].tex_ptr);
}

static void	cleanup_resources(t_program *p)
{
	free_textures(p->wall_texture, 4, p->mlx);
	if (p->main_image.img_ptr)
		mlx_destroy_image(p->mlx, p->main_image.img_ptr);
	free_textures_paths(p);
	free_file(&p->map);
	if (p->mlx_win)
		mlx_destroy_window(p->mlx, p->mlx_win);
	if (p->mlx)
	{
		mlx_destroy_display(p->mlx);
		free(p->mlx);
	}
}

int	safe_exit(t_program *program)
{
	cleanup_resources(program);
	exit(EXIT_SUCCESS);
	return (0);
}
