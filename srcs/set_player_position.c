/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:37:47 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/22 17:36:08 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	set_player_position(t_raycasting *raycasting, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				raycasting->start_dir = map[y][x];
				raycasting->map_position_x = x;
				raycasting->map_position_y = y;
				raycasting->pp_x = x + 0.5;
				raycasting->pp_y = y + 0.5;
			}
			x++;
		}
		y++;
	}
}
