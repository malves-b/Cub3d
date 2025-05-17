/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:35:22 by jesilva-          #+#    #+#             */
/*   Updated: 2025/05/17 16:35:24 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static bool	check_player_valid(t_parse *parse, int x, int y)
{
	if ((parse->map[x][y] == 'N' || parse->map[x][y] == 'S'
		|| parse->map[x][y] == 'E' || parse->map[x][y] == 'W')
		&& parse->parse_player == '\0')
	{
		parse->parse_x = x;
		parse->parse_y = y;
		parse->parse_player = parse->map[x][y];
	}
	else if (((parse->map[x][y] == 'N' || parse->map[x][y] == 'S'
		|| parse->map[x][y] == 'E' || parse->map[x][y] == 'W')
		&& parse->parse_player != '\0'))
	{
		printf("Error\nInvalid map player is duplicated!\n");
		return (false);
	}
	else if (parse->map[x][y] != 'N' && parse->map[x][y] != 'S'
		&& parse->map[x][y] != 'E' && parse->map[x][y] != 'W'
		&& parse->map[x][y] != '0' && parse->map[x][y] != '1'
		&& !ft_isspace(parse->map[x][y]))
	{
		printf("Error\nInvalid map! The map contains invalid characters!\n");
		return (false);
	}
	return (true);
}

static bool	check_player(t_parse *parse)
{
	if (!parse->parse_player)
	{
		printf("Error\nInvalid map player, player not found!\n");
		return (false);
	}
	return (true);
}

bool	val_map(t_parse *parse)
{
	int	x;
	int	y;

	x = 0;
	while (parse->map[x])
	{
		y = 0;
		if (parse->map[x][0] == '\0')
		{
			printf("Error\nInvalid map!\n");
			return (false);
		}
		while (parse->map[x][y] != '\0')
		{
			if (!check_player_valid(parse, x, y))
				return (false);
			y++;
		}
		x++;
	}
	if (!check_player(parse))
		return (false);
	return (true);
}

void	exit_map_message(t_main *cub)
{
	printf("Error\nInvalid map!\n");
	free_parse(cub->parse);
	free(cub);
	exit (1);
}

void	validate_map(t_parse *parse)
{
	if (parse->map == NULL)
		exit_map_message(parse->cub);
}
