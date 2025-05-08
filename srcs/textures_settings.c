/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:23:31 by malves-b          #+#    #+#             */
/*   Updated: 2025/05/08 19:25:03 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_image	*load_texture(t_main *pgr, const char *path);

int	ft_init_textures(t_main *pgr)
{
	pgr->texture_north = load_texture(pgr, "/home/malves-b/sgoinfre/Rank_04/Cub3d/textures/north_wall.xpm");
	pgr->texture_south = load_texture(pgr, "/home/malves-b/sgoinfre/Rank_04/Cub3d/textures/south_wall.xpm");
	pgr->texture_west = load_texture(pgr, "/home/malves-b/sgoinfre/Rank_04/Cub3d/textures/west_wall.xpm");
	pgr->texture_east = load_texture(pgr, "/home/malves-b/sgoinfre/Rank_04/Cub3d/textures/east_wall.xpm");
	if (!pgr->texture_north || !pgr->texture_south || !pgr->texture_east
		|| !pgr->texture_west)
		return (1);
	return (0);	
}

t_image	*load_texture(t_main *pgr, const char *path)
{
	t_image	*texture;

	texture = safe_calloc(pgr, sizeof(t_image));
	texture->img_ptr = mlx_xpm_file_to_image(pgr->mlx->mlx,
		(char *)path, &texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		free(texture);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
		&texture->line_len, &texture->endian);
	return (texture);
}