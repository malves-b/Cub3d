/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:39:22 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/23 15:02:45 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	render_frame(t_main *pgr)
{
	int x;
	double camera_x;
	double ray_dir_x;
	double ray_dir_y;

	x = 0;
	draw_background(pgr);
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		// Calculando direção do raio baseado na direção do jogador e plano da câmera
		ray_dir_x = pgr->ray->dir_x + pgr->ray->plane_vector[0] * camera_x;
		ray_dir_y = pgr->ray->dir_y + pgr->ray->plane_vector[1] * camera_x;

		pgr->ray->map_position_x = (int)pgr->ray->pp_x;
		pgr->ray->map_position_y = (int)pgr->ray->pp_y;
		
		// Delta distance
		pgr->ray->deltaDistX = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
		pgr->ray->deltaDistY = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);

		// Determina step e distancia inicial para o lado
		if (ray_dir_x < 0)
		{
			pgr->ray->stepX = -1;
			pgr->ray->sideDistX = (pgr->ray->pp_x - pgr->ray->map_position_x) * pgr->ray->deltaDistX;
		}
		else
		{
			pgr->ray->stepX = 1;
			pgr->ray->sideDistX = (pgr->ray->map_position_x + 1.0 - pgr->ray->pp_x) * pgr->ray->deltaDistX;
		}
		if (ray_dir_y < 0)
		{
			pgr->ray->stepY = -1;
			pgr->ray->sideDistY = (pgr->ray->pp_y - pgr->ray->map_position_y) * pgr->ray->deltaDistY;
		}
		else
		{
			pgr->ray->stepY = 1;
			pgr->ray->sideDistY = (pgr->ray->map_position_y + 1.0 - pgr->ray->pp_y) * pgr->ray->deltaDistY;
		}

		pgr->ray->hit_wall = 0;
		while (pgr->ray->hit_wall == 0)
		{
			if (pgr->ray->sideDistX < pgr->ray->sideDistY)
			{
				pgr->ray->sideDistX += pgr->ray->deltaDistX;
				pgr->ray->map_position_x += pgr->ray->stepX;
				pgr->ray->side = 0;
			}
			else
			{
				pgr->ray->sideDistY += pgr->ray->deltaDistY;
				pgr->ray->map_position_y += pgr->ray->stepY;
				pgr->ray->side = 1;
			}
			if (pgr->map[pgr->ray->map_position_y][pgr->ray->map_position_x] == '1')
				pgr->ray->hit_wall = 1;
		}

		if (pgr->ray->side == 0)
			pgr->ray->perpWallDist = (pgr->ray->sideDistX - pgr->ray->deltaDistX);
		else
			pgr->ray->perpWallDist = (pgr->ray->sideDistY - pgr->ray->deltaDistY);

		int line_height = (int)(HEIGHT / pgr->ray->perpWallDist);
		int draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;

		int color;
		if (pgr->ray->side == 1) // parede horizontal (N/S)
		{
			if (pgr->ray->stepY > 0)
				color = RED;
			else
				color = RED_LIGHT;
		}
		else
		{
			if (pgr->ray->stepX > 0)
				color = YELLOW;
			else
				color = GREEN;
		}
			

		int y = draw_start;
		while (y < draw_end)
			my_put_pixel(pgr->mlx, x, y++, color);
		x++;
	}
	mlx_put_image_to_window(pgr->mlx->mlx, pgr->mlx->mlx_win, pgr->mlx->img, 0, 0);
}
