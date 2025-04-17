/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:37:47 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/17 15:04:53 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	set_player_position(t_raycasting *raycasting, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == 'N' || map[x][y] == 'S'
				|| map[x][y] == 'E' || map[x][y] == 'W')
			{
				raycasting->map_position[1] = x;
				raycasting->map_position[0] = y;
				raycasting->pp[1] = x + 0.5;
				raycasting->pp[0] = y + 0.5;
			}
			y++;
		}
		y = 0;
		x++;
	}
}
