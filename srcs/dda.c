/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:24:11 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/22 18:53:24 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	dda(t_raycasting *ray)
{
	while (ray->hit_wall)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->map_position_x += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->map_position_y += ray->stepY;
			ray->side = 1;
		}
		if (ray->mainstruct->map[ray->map_position_y][ray->map_position_x] > 0) // change x <-> y
			ray->hit_wall = 1;
	}
}