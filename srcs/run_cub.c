/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:53 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/16 14:45:56 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_component(t_main *pgr, int color, int map_x, int map_y);
void	draw_map(t_main *pgr);

void	finish_cub(t_main *pgr)
{
	ft_free(pgr);
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_main *pgr)
{
	int	pp_x;
	int	pp_y;

	pp_x = pgr->raycasting->player_position[0];
	pp_y = pgr->raycasting->player_position[1];
	if (keycode == KEY_LEFT)
		pp_x -= 1;
	if (keycode == KEY_RIGHT)
		pp_x += 1;
	if (keycode == KEY_UP)
		pp_y -= 1;
	if (keycode == KEY_DOWN)
		pp_y += 1;
	if (keycode == KEY_ESC)
	{
		puts("ESC PRESSED");
		finish_cub(pgr);
		exit(1);
	}
	if (pgr->map[pp_y][pp_x] != '1')
	{
		pgr->raycasting->player_position[0] = pp_x;
		pgr->raycasting->player_position[1] = pp_y;
	}
	// mlx_destroy_image(pgr, )
	draw_component(pgr, RED, pgr->raycasting->player_position[0], pgr->raycasting->player_position[1]);
	// mlx_clear_window(pgr->mlx->mlx, pgr->mlx->mlx_win);
	return (1);
}

void draw_component(t_main *pgr, int color, int map_x, int map_y)
{
	int	x;
	int	y;
    int offset_x;
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
                my_mlx_pixel_put(pgr->mlx->mlx_win, pgr->mlx->img, x, y, color);
            offset_y++;
        }
        offset_x++;
    }
	mlx_put_image_to_window(pgr->mlx->mlx, pgr->mlx->mlx_win, pgr->mlx->img, 0, 0);
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
			else if (pgr->map[y][x] == '0')
				draw_component(pgr, GRAY, x, y);
			else
				draw_component(pgr, RED, x, y);
			x++;
		}
		y++;
	}
}
