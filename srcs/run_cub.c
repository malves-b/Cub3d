/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:53 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/22 18:12:38 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_component(t_main *pgr, int color, double map_x, double map_y);
void	draw_map(t_main *pgr);
void	my_put_pixel(t_mlx *mlx, int x, int y, int color);

void	draw_direction(t_main *pgr); /**/
void	rotate_player(t_raycasting *ray, double angle); /**/

#define ROT_SPEED 0.05
#define SCALE 10

void	check_next_pos(t_main *pgr)
{
	double next_x;
	double next_y;

	next_x = pgr->ray->pp_x + pgr->ray->dir_x * 0.3;
	next_y = pgr->ray->pp_y + pgr->ray->dir_y * 0.3;
	printf("PP[0] = %f\n", pgr->ray->pp_x);
	printf("PP[1] = %f\n", pgr->ray->pp_y);
	printf("Next X = %f\n", next_x);
	printf("Next Y = %f\n", next_y);
	printf("Dist to X = %f\n", pgr->ray->deltaDistX);
	printf("Dist to Y = %f\n", pgr->ray->deltaDistY);

	if (pgr->map[(int)next_y][(int)pgr->ray->pp_x] != '1')
	{
		if (pgr->map[(int)next_y][(int)pgr->ray->pp_x] != '1')
		{
			puts("--------- ENTROU -------\n");
			pgr->ray->pp_y = next_y;
		}
	}
	if (pgr->map[(int)pgr->ray->pp_y][(int)next_x] != '1')
	{
		if (pgr->map[(int)pgr->ray->pp_y][(int)next_x] != '1')
		{
			pgr->ray->pp_x = next_x;
		}
	}
}

int	key_press(int keycode, t_main *pgr)
{
	int	pp_x;
	int	pp_y;

	pp_x = (int)pgr->ray->pp_x;
	pp_y = (int)pgr->ray->pp_y;
	if (keycode == KEY_UP)
	{
		check_next_pos(pgr);
	}
	if (keycode == KEY_DOWN)
	{
		double next_x = pgr->ray->pp_x - pgr->ray->dir_x * 0.3;
		double next_y = pgr->ray->pp_y - pgr->ray->dir_y * 0.3;
	
		if (pgr->map[(int)next_y][(int)pgr->ray->pp_x] != '1')
			pgr->ray->pp_y = next_y;
		if (pgr->map[(int)pgr->ray->pp_y][(int)next_x] != '1')
			pgr->ray->pp_x = next_x;
	}	if (keycode == KEY_LEFT)
		rotate_player(pgr->ray, -ROT_SPEED);
	if (keycode == KEY_RIGHT)
		rotate_player(pgr->ray, ROT_SPEED);
	if (keycode == KEY_ESC)
	{
		puts("ESC PRESSED");
		ft_free(pgr);
		exit(EXIT_SUCCESS);
	}
	ft_bzero(pgr->mlx->img_addr, WIDTH * HEIGHT);
	draw_map(pgr);
	draw_component(pgr, RED, pgr->ray->pp_x, pgr->ray->pp_y);
	draw_direction(pgr);
	
	mlx_put_image_to_window(pgr->mlx->mlx, pgr->mlx->mlx_win, pgr->mlx->img, 0, 0);
	return (1);
}

void my_put_pixel(t_mlx *mlx, int x, int y, int color)
{
    int offset;

    offset = (y * mlx->line_length) + (x * (mlx->bits_per_pixel / 8));
    *((unsigned int *)(mlx->img_addr + offset)) = color;
}

void draw_component(t_main *pgr, int color, double map_x, double map_y)
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

void draw_map(t_main *pgr)
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

void draw_direction(t_main *pgr)
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


void rotate_player(t_raycasting *ray, double angle)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = ray->dir_x;
	old_plane_x = ray->plane_vector[0];
	ray->dir_x = ray->dir_x * cos(angle) - ray->dir_y * sin(angle);
	ray->dir_y = old_dir_x * sin(angle) + ray->dir_y * cos(angle);

	ray->plane_vector[0] = ray->plane_vector[0] * cos(angle) - ray->plane_vector[1] * sin(angle);
	ray->plane_vector[1] = old_plane_x * sin(angle) + ray->plane_vector[1] * cos(angle);
}
