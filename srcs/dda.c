/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:24:11 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/23 13:03:38 by malves-b         ###   ########.fr       */
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

//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect)
void	calc_dist(t_raycasting *ray)
{
	if (ray->side == 0)
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX); 
	else
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
}

//Calculate height of line to draw on screen
void	calc_line_height(t_raycasting *ray)
{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;

	lineHeight = (int)(ray->hit_wall / ray->perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	drawStart = -lineHeight / 2 + ray->hit_wall / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + ray->hit_wall / 2;
	if (drawEnd >= ray->hit_wall)
		drawEnd = ray->hit_wall - 1;
}

//choose wall color
void	set_wall_color()
{
	ColorRGB color;
	switch(worldMap[mapX][mapY])
	{
	case 1:  color = RGB_Red;  break; //red
	case 2:  color = RGB_Green;  break; //green
	case 3:  color = RGB_Blue;   break; //blue
	case 4:  color = RGB_White;  break; //white
	default: color = RGB_Yellow; break; //yellow
	}

	//give x and y sides different brightness
	if (side == 1) {color = color / 2;}

	//draw the pixels of the stripe as a vertical line
	verLine(x, drawStart, drawEnd, color);
}