/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:53 by malves-b          #+#    #+#             */
/*   Updated: 2025/03/05 17:28:22 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	key_press(int keycode, t_main *pgr)
{
	if (keycode == KEY_LEFT)
	{
		pgr->player_position[0] -= 5;
	}
	if (keycode == KEY_RIGHT)
	{
		pgr->player_position[0] += 5;
	}
	if (keycode == KEY_UP)
	{
		pgr->player_position[1] -= 5;
	}
	if (keycode == KEY_DOWN)
	{
		pgr->player_position[1] += 5;
	}
	mlx_clear_window(pgr->mlx.mlx, pgr->mlx.mlx_win);
	// draw_player(pgr);
	return (1);
}