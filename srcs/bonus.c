/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:14:19 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/23 19:21:51 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

#define SCALE 10

void	draw_component(t_main *pgr, int color, double map_x, double map_y)
{
	int	x;
	int	y;
	int	offset_x;
	int	offset_y;

	offset_x = -3;
	while (offset_x <= 3)
	{
		offset_y = -3;
		while (offset_y <= 3)
		{
			x = map_x * 10 + offset_x;
			y = map_y * 10 + offset_y;
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
				my_put_pixel(pgr->mlx, x, y, color);
			offset_y++;
		}
		offset_x++;
	}
}

void	draw_direction(t_main *pgr)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i <= 10)
	{
		x = (pgr->ray->pp_x + pgr->ray->dir_x * i * 0.1) * SCALE;
		y = (pgr->ray->pp_y + pgr->ray->dir_y * i * 0.1) * SCALE;
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			my_put_pixel(pgr->mlx, x, y, GREEN);
		i++;
	}
}

void	draw_mini_map(t_main *pgr)
{
	int	x;
	int	y;

	y = 0;
	while (pgr->map[y])
	{
		x = 0;
		while (pgr->map[y][x])
		{
			if (pgr->map[y][x] == '1')
				draw_component(pgr, BROWN, x, y);
			else
				draw_component(pgr, GRAY, x, y);
			x++;
		}
		y++;
	}
}

void	bonus(t_main *pgr)
{
	draw_mini_map(pgr);
}
