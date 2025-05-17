/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:33:57 by jesilva-          #+#    #+#             */
/*   Updated: 2025/05/17 16:33:58 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	init_parse_struct(t_parse *parse)
{
	parse->no_path = NULL;
	parse->so_path = NULL;
	parse->we_path = NULL;
	parse->ea_path = NULL;
	parse->floor_color = NULL;
	parse->ceiling_color = NULL;
	parse->file = NULL;
	parse->map = NULL;
	parse->temp_map = NULL;
	parse->max_width = 0;
	parse->is_valid = false;
	parse->file_lines = 0;
	parse->parse_player = '\0';
	parse->parse_x = 0;
	parse->parse_y = 0;
}

void	init_smap(t_map *map)
{
	map->map = NULL;
}

void	init_texture(t_texture *texture)
{
	texture->no_path = NULL;
	texture->so_path = NULL;
	texture->we_path = NULL;
	texture->ea_path = NULL;
}

void	init_player(t_player *player)
{
	player->player = '\0';
	player->x = 0;
	player->y = 0;
}

void	init_struct(t_main *cub)
{
	init_parse_struct(cub->parse);
}
