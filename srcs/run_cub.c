/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:53 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/16 19:10:58 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_component(t_main *pgr, int color, int map_x, int map_y);
void	draw_map(t_main *pgr);
void	my_put_pixel(t_mlx *mlx, int x, int y, int color);
void	update_pp(t_main *pgr, int pp_x, int pp_y);

int	key_press(int keycode, t_main *pgr)
{
	int	pp_x;
	int	pp_y;

	pp_x = (int)pgr->raycasting->player_position[0];
	pp_y = (int)pgr->raycasting->player_position[1];
	if (keycode == KEY_LEFT && pgr->map[pp_x - 1][pp_y] != '1')
		pp_x -= 0.3;
	if (keycode == KEY_RIGHT && pgr->map[pp_x + 1][pp_y] != '1')
		pp_x += 0.3;
	if (keycode == KEY_UP && pgr->map[pp_x][pp_y -1] != '1')
		pp_y -= 0.3;
	if (keycode == KEY_DOWN && pgr->map[pp_x][pp_y + 1] != '1')
		pp_y += 0.3;
	if (keycode == KEY_ESC)
	{
		puts("ESC PRESSED");
		ft_free(pgr);
		exit(EXIT_SUCCESS);
	}
	draw_map(pgr);
	return (1);
}

void my_put_pixel(t_mlx *mlx, int x, int y, int color)
{
    int offset;

    offset = (y * mlx->line_length) + (x * (mlx->bits_per_pixel / 8));
    *((unsigned int *)(mlx->img_addr + offset)) = color;
}

void update_pp(t_main *pgr, int pp_x, int pp_y)
{
	int cur_x = (int)pgr->raycasting->player_position[0];
	int cur_y = (int)pgr->raycasting->player_position[1];

	if (cur_x >= 0 && cur_y >= 0 && pgr->map[cur_x] && pgr->map[cur_x][cur_y])
		pgr->map[cur_x][cur_y] = '0';

	if (pp_x >= 0 && pp_y >= 0 && pgr->map[pp_x] && pgr->map[pp_x][pp_y])
		pgr->map[pp_x][pp_y] = 'P';

	pgr->raycasting->player_position[0] = pp_x;
	pgr->raycasting->player_position[1] = pp_y;
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
			else if (pgr->map[y][x] == '0')
				draw_component(pgr, GRAY, x, y);
			else
				draw_component(pgr, RED, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(pgr->mlx->mlx, pgr->mlx->mlx_win, pgr->mlx->img, 0, 0);
}
