/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:03:48 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/23 19:07:12 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	set_sidedist(t_raycasting *ray);

t_raycasting	*init_raycasting(t_main *pgr)
{
	t_raycasting	*ray;

	ray = safe_calloc(pgr, sizeof(t_raycasting));
	set_player_position(ray, pgr->map);
	set_direction_vector(ray->start_dir, ray);
	ray->deltaDistX = fabs(1 / ray->dir_x);
	ray->deltaDistY = fabs(1 / ray->dir_y);
	set_sidedist(ray);
	ray->perpWallDist = 0;
	ray->mainstruct = pgr;
	return (ray);
}

void	set_sidedist(t_raycasting *ray)
{
	if (ray->dir_x < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->pp_x - ray->map_position_x)
			* ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->map_position_x + 1.0
				- ray->pp_x) * ray->deltaDistX;
	}
	if (ray->dir_y < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->pp_y - ray->map_position_y) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->map_position_y + 1.0 - ray->pp_y)
			* ray->deltaDistY;
	}
}
