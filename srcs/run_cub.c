/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:53 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/14 20:28:59 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	key_press(int keycode, t_main *pgr)
{
	if (keycode == KEY_LEFT)
	{
		pgr->raycasting->player_position[0] -= 5;
	}
	if (keycode == KEY_RIGHT)
	{
		pgr->raycasting->player_position[0] += 5;
	}
	if (keycode == KEY_UP)
	{
		pgr->raycasting->player_position[1] -= 5;
	}
	if (keycode == KEY_DOWN)
	{
		pgr->raycasting->player_position[1] += 5;
	}
	mlx_clear_window(pgr->mlx.mlx, pgr->mlx.mlx_win);
	draw_player(pgr);
	return (1);
}