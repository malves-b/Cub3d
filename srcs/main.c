/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:10 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/14 21:05:17 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	cub_init(t_main *pgr)
{
	pgr->map = ft_calloc(sizeof(char *), 12);
	pgr->map[1] = "11111111111111111111111";
	pgr->map[2] = "10000000000000000000001";
	pgr->map[3] = "10000000000000000000001";
	pgr->map[4] = "10000000000000000000001";
	pgr->map[5] = "11111111111100000100001";
	pgr->map[6] = "11111111111100000000001";
	pgr->map[7] = "11111111111100000000001";
	pgr->map[8] = "11111111111100000000001";
	pgr->map[9] = "11111111111100000000001";
	pgr->map[10] = "11111111111100000000001";
	pgr->map[11] = "11111111111100000N00001";
	pgr->map[12] = "11111111111111111111111";

	pgr->mlx = init_mlx();
	pgr->raycasting = init_raycasting(pgr);
	mlx_pixel_put(pgr->mlx->mlx, pgr->mlx->mlx_win, 200, 200, RED);
	// mlx_hook(pgr->mlx.mlx_win, 2, 1L << 0, key_press, pgr->mlx.img);
	mlx_loop(pgr->mlx->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	*cub;

	if (!check_args(argc ,argv[1], argv[0]))
		return (1);
	cub = NULL;
	cub = safe_calloc(cub, sizeof(t_main));
	cub->parse = safe_calloc(cub, sizeof(t_parse));
	init_parse_struct(cub->parse);
	if(!ft_read_file(cub->parse, argv[1]))
		return (1);
	cub_init(cub);
	//readmap guardar em algum lugar
	//fazer a validadação
	// free_parse(cub->parse);
	// free(cub);
	return (0);
}
