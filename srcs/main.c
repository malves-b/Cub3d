/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:10 by malves-b          #+#    #+#             */
/*   Updated: 2025/05/08 18:52:18 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	cub_init(t_main *pgr)
{
	pgr->map = ft_calloc(sizeof(char *), 13);
	pgr->map[0] = "11111111111111111111111";
	pgr->map[1] = "10000000000000000000001";
	pgr->map[2] = "10011N00000000000000001";
	pgr->map[3] = "10000000000000001100001";
	pgr->map[4] = "11111111111100001100001";
	pgr->map[5] = "11111111111100000000001";
	pgr->map[6] = "11111111111100000000001";
	pgr->map[7] = "11111111111100000000001";
	pgr->map[8] = "11111111111100000000001";
	pgr->map[9] = "11111111111100000000001";
	pgr->map[10] = "11111111111100000000001";
	pgr->map[11] = "11111111111111111111111";
	pgr->map[12] = NULL;
	pgr->mlx = init_mlx();
	pgr->ray = init_raycasting(pgr);
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
	init_parse_struct(cub->parse);
	if (!ft_read_file(cub->parse, argv[1]))
		return (1);
	cub_init(cub);
	return (0);
}
