/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:03:48 by malves-b          #+#    #+#             */
/*   Updated: 2025/05/15 10:26:52 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	set_sidedist(t_raycasting *ray);

t_raycasting	*init_raycasting(t_main *pgr)
{
	t_raycasting	*ray;

	ray = safe_calloc(pgr, sizeof(t_raycasting));
	set_player_position(ray, pgr->smap->map);
	set_direction_vector(ray->start_dir, ray);
	ray->dltdistx = fabs(1 / ray->dir_x);
	ray->dltdisty = fabs(1 / ray->dir_y);
	set_sidedist(ray);
	ray->prp_walldst = 0;
	return (ray);
}

void	set_sidedist(t_raycasting *ray)
{
	if (ray->dir_x < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->pp_x - ray->map_position_x)
			* ray->dltdistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->map_position_x + 1.0
				- ray->pp_x) * ray->dltdistx;
	}
	if (ray->dir_y < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->pp_y - ray->map_position_y) * ray->dltdisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->map_position_y + 1.0 - ray->pp_y)
			* ray->dltdisty;
	}
}
