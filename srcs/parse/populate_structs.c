/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:34:23 by jesilva-          #+#    #+#             */
/*   Updated: 2025/05/17 16:34:25 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	populate_structs(t_parse *parse, t_main *cub)
{
	cub->smap = malloc(sizeof(t_map));
	cub->player = malloc(sizeof(t_player));
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->player || !cub->texture || !cub->smap)
	{
		printf("Error\n Memory allocation error\n");
		exit (1);
	}
	copy_map(cub->parse->map, &cub->smap->map);
	copy_player(parse, cub->player);
	copy_textures(parse, cub->texture);
}

void	copy_textures(t_parse *parse, t_texture *texture)
{
	texture->no_path = ft_strdup(parse->no_path);
	texture->so_path = ft_strdup(parse->so_path);
	texture->we_path = ft_strdup(parse->we_path);
	texture->ea_path = ft_strdup(parse->ea_path);
	texture->floor_color = parse->hexa_floor;
	texture->ceiling_color = parse->hexa_ceiling;
}

void	copy_player(t_parse *parse, t_player *player)
{
	player->player = parse->parse_player;
	player->x = parse->parse_x;
	player->y = parse->parse_y;
}

void	copy_map(char **src, char ***dest)
{
	int	i;
	int	lines;

	lines = 0;
	while (src[lines])
		lines++;
	*dest = malloc(sizeof(char *) * (lines + 1));
	if (!*dest)
	{
		printf("Error\n Memory allocation error\n");
		return ;
	}
	i = 0;
	while (i < lines)
	{
		(*dest)[i] = ft_strdup(src[i]);
		i++;
	}
	(*dest)[i] = NULL;
}
