/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:53 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/15 10:39:46 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	finish_cub(t_main *pgr)
{
	ft_free(pgr);
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_main *pgr)
{
	if (keycode == KEY_LEFT)
	{
		pgr->raycasting->player_position[0] -= 10;
	}
	if (keycode == KEY_RIGHT)
	{
		pgr->raycasting->player_position[0] += 10;
	}
	if (keycode == KEY_UP)
	{
		pgr->raycasting->player_position[1] -= 10;
	}
	if (keycode == KEY_DOWN)
	{
		pgr->raycasting->player_position[1] += 10;
	}
	if (keycode == KEY_ESC)
	{
		puts("ESC PRESSED");
		finish_cub(pgr);
		exit(1);
	}
	mlx_clear_window(pgr->mlx->mlx, pgr->mlx->mlx_win);
	mlx_pixel_put(pgr->mlx->mlx, pgr->mlx->mlx_win, pgr->raycasting->player_position[0], pgr->raycasting->player_position[1], RED);
	return (1);
}