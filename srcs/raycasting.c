/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:39:22 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/24 15:41:11 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

#include <limits.h>

int		set_color(t_raycasting *ray); /* REMOVE */

void	set_delta_dist(t_main *pgr, double ray_dir_x, double ray_dir_y);
void	set_step(t_raycasting *ray, double ray_dir_x, double ray_dir_y);
void	throw_ray(t_raycasting *ray, char **map);
void	draw_wall(t_main *pgr, int x);

void	render_frame(t_main *pgr)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	x = -1;
	draw_background(pgr);
	while (++x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		ray_dir_x = pgr->ray->dir_x + pgr->ray->plane_vector[0] * camera_x;
		ray_dir_y = pgr->ray->dir_y + pgr->ray->plane_vector[1] * camera_x;
		pgr->ray->map_position_x = (int)pgr->ray->pp_x;
		pgr->ray->map_position_y = (int)pgr->ray->pp_y;
		set_delta_dist(pgr, ray_dir_x, ray_dir_y);
		set_step(pgr->ray, ray_dir_x, ray_dir_y);
		throw_ray(pgr->ray, pgr->map);
		if (pgr->ray->side == 0)
			pgr->ray->prp_walldst = (pgr->ray->sidedistx - pgr->ray->dltdistx);
		else
			pgr->ray->prp_walldst = (pgr->ray->sidedisty - pgr->ray->dltdisty);
		draw_wall(pgr, x);
	}
	mlx_put_image_to_window(pgr->mlx->mlx, pgr->mlx->mlx_win,
		pgr->mlx->img, 0, 0);
}

int	set_color(t_raycasting *ray)
{
	int	color;

	if (ray->side == 1)
	{
		if (ray->stepy > 0)
			color = RED;
		else
			color = RED_LIGHT;
	}
	else
	{
		if (ray->stepx > 0)
			color = YELLOW;
		else
			color = GREEN;
	}
	return (color);
}

void	set_delta_dist(t_main *pgr, double ray_dir_x, double ray_dir_y)
{
	if (ray_dir_x == 0)
		pgr->ray->dltdistx = INT_MAX;
	else
		pgr->ray->dltdistx = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		pgr->ray->dltdisty = INT_MAX;
	else
		pgr->ray->dltdisty = fabs(1 / ray_dir_y);
}

/** @brief Set step and start side distance */
void	set_step(t_raycasting *ray, double ray_dir_x, double ray_dir_y)
{
	if (ray_dir_x < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->pp_x - ray->map_position_x) * ray->dltdistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->map_position_x + 1.0 - ray->pp_x)
			* ray->dltdistx;
	}
	if (ray_dir_y < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->pp_y - ray->map_position_y)
			* ray->dltdisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->map_position_y + 1.0 - ray->pp_y)
			* ray->dltdisty;
	}
}

/** @brief Function throw ray till hit a wall */
void	throw_ray(t_raycasting *ray, char **map)
{
	ray->hit_wall = 0;
	while (ray->hit_wall == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->dltdistx;
			ray->map_position_x += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->dltdisty;
			ray->map_position_y += ray->stepy;
			ray->side = 1;
		}
		if (map[ray->map_position_y][ray->map_position_x] == '1')
			ray->hit_wall = 1;
	}
}

/** @brief Draws a vertical wall stripe on screen based on the calculated 
 * distance to the wall. Uses raycasting data to determine height and color 
 * for each pixel column. */
void	draw_wall(t_main *pgr, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	y;

	line_height = (int)(HEIGHT / pgr->ray->prp_walldst);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	y = draw_start;
	while (y < draw_end)
		my_put_pixel(pgr->mlx, x, y++, set_color(pgr->ray));
}
