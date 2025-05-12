/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:23:31 by malves-b          #+#    #+#             */
/*   Updated: 2025/05/12 15:18:54 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_image	*load_texture(t_main *pgr, char *path);

int	ft_init_textures(t_main *pgr)
{
	pgr->texture_north = load_texture(pgr,
			"/home/malves-b/Common-core/Cub3d/textures/n.xpm");
	pgr->texture_south = load_texture(pgr,
			"/home/malves-b/Common-core/Cub3d/textures/s.xpm");
	pgr->texture_west = load_texture(pgr,
			"/home/malves-b/Common-core/Cub3d/textures/w.xpm");
	pgr->texture_east = load_texture(pgr,
			"/home/malves-b/Common-core/Cub3d/textures/e.xpm");
	if (!pgr->texture_north || !pgr->texture_south || !pgr->texture_east
		|| !pgr->texture_west)
		return (1);
	return (0);
}

t_image	*load_texture(t_main *pgr, char *path)
{
	t_image	*texture;

	texture = safe_calloc(pgr, sizeof(t_image));
	texture->img_ptr = mlx_xpm_file_to_image(pgr->mlx->mlx,
			path, &texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		free(texture);
		return (NULL);
	}
	if ((texture->width & (texture->width - 1)) != 0
		|| (texture->height & (texture->height - 1)) != 0)
	{
		printf("Error: Texture %s dimensions must be power of 2\n", path);
		mlx_destroy_image(pgr->mlx->mlx, texture->img_ptr);
		free(texture);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->line_len, &texture->endian);
	return (texture);
}
