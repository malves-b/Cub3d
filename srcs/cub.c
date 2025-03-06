/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:10 by malves-b          #+#    #+#             */
/*   Updated: 2025/03/06 15:47:28 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	cub_init(void)
{
	t_main	*pgr;

	pgr = NULL;
	pgr = safe_calloc(pgr, sizeof(t_main));
	pgr->mlx = init_mlx();
	pgr->raycasting = init_raycasting(pgr);
	// draw_player(pgr);
	// mlx_hook(pgr->mlx.mlx_win, 2, 1L << 0, key_press, pgr->mlx.img);
	mlx_loop(pgr->mlx->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	cub_init();
	return (0);
}
