/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:34:55 by jesilva-          #+#    #+#             */
/*   Updated: 2025/05/17 16:34:56 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	remove_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

static int	get_max_width(char **map, int height, t_parse *parse)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < height)
	{
		len = ft_strlen(map[i]);
		if (len > parse->max_width)
			parse->max_width = len;
		i++;
	}
	return (parse->max_width);
}

bool	init_map_rectangular(char **map, char **map_rec, t_parse *parse, int i)
{
	int	j;

	j = 0;
	if (map[i][j] == '\0')
	{
		free_array(&map_rec);
		return (false);
	}
	map_rec[i] = malloc(sizeof(char) * (parse->max_width + 1));
	if (!map_rec[i])
		return (false);
	while (map[i][j])
	{
		map_rec[i][j] = map[i][j];
		j++;
	}
	while (j < parse->max_width)
		map_rec[i][j++] = ' ';
	map_rec[i][j] = '\0';
	return (true);
}

char	**make_rectangular(char **map, int height, t_parse *parse)
{
	char	**map_rec;
	int		i;

	i = 0;
	parse->max_width = get_max_width(map, height, parse);
	map_rec = ft_calloc(sizeof(char *), (height + 1));
	if (!map_rec)
		return (NULL);
	while (i < height)
	{
		if (!init_map_rectangular(map, map_rec, parse, i))
			return (NULL);
		i++;
	}
	map_rec[height] = NULL;
	return (map_rec);
}

void	check_texture_is_valid(t_parse *parse)
{
	if (parse->no_path != NULL && parse->so_path != NULL
		&& parse->we_path != NULL && parse->ea_path != NULL
		&& parse->floor_color != NULL && parse->ceiling_color != NULL)
	{
		parse->is_valid = true;
	}
}
