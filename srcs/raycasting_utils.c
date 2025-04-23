/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:00:26 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/23 15:01:11 by malves-b         ###   ########.fr       */
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

