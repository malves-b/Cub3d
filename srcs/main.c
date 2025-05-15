/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:10 by malves-b          #+#    #+#             */
/*   Updated: 2025/05/15 10:49:56 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	cub_init(t_main *pgr)
{
	pgr->mlx = init_mlx();
	pgr->ray = init_raycasting(pgr);
	if (ft_init_textures(pgr))
	{
		close_program(pgr);
	}
	key_press(32, pgr);
	mlx_hook(pgr->mlx->mlx_win, 17, 0, close_program, pgr);
	mlx_hook(pgr->mlx->mlx_win, 2, 1L << 0, key_press, pgr);
	mlx_loop(pgr->mlx->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	*cub;

	if (!check_args(argc, argv[1], argv[0]))
		return (1);
	cub = NULL;
	cub = safe_calloc(cub, sizeof(t_main));
	cub->parse = safe_calloc(cub, sizeof(t_parse));
	if (!init_parse_info(cub, argv[1]))
	{
		ft_exit(cub);
		return (1);
	}
	cub_init(cub);
	return (0);
}
