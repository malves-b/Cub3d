/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:10 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/14 19:18:02 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	cub_init(t_main *pgr)
{
	pgr->mlx = init_mlx();
	pgr->raycasting = init_raycasting(pgr);
	// draw_player(pgr);
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
	if (!init_parse_info(cub, argv[1]))
	{
		// free_parse(cub->parse);
		// free(cub);
		return (1);
	}
	cub_init(cub);
	//readmap guardar em algum lugar
	//fazer a validadação
	// free_parse(cub->parse);
	// free(cub);
	return (0);
}
