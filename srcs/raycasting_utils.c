/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:00:26 by malves-b          #+#    #+#             */
/*   Updated: 2025/05/12 15:50:44 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/** @brief Function paint the floor and sky*/
void	draw_background(t_main *pgr)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				my_put_pixel(pgr->mlx, x, y, COLOR_SKY);
			else
				my_put_pixel(pgr->mlx, x, y, COLOR_FLOOR);
			x++;
		}
		y++;
	}
}

/** @brief Function calc the value of x position in the texture*/
void	calc_x(t_main *pgr, double ray_dir_x, double ray_dir_y, int tex_width)
{
	if (pgr->ray->side == 0)
		pgr->ray->wall_x = pgr->ray->pp_y + pgr->ray->prp_walldst * ray_dir_y;
	else
		pgr->ray->wall_x = pgr->ray->pp_x + pgr->ray->prp_walldst * ray_dir_x;
	pgr->ray->wall_x -= floor(pgr->ray->wall_x);
	pgr->ray->tex_x = (int)(pgr->ray->wall_x * (double)tex_width);
	if ((pgr->ray->side == 0 && ray_dir_x < 0)
		|| (pgr->ray->side == 1 && ray_dir_y > 0))
		pgr->ray->tex_x = tex_width - pgr->ray->tex_x - 1;
}
