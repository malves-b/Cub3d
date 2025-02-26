/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:10 by malves-b          #+#    #+#             */
/*   Updated: 2025/02/26 20:05:39 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_main	*init_window(t_main *pgr)
{
    pgr = (t_main *)malloc(sizeof(t_main));
    if (!pgr)
        return (NULL);
    ft_memset(pgr, 0, sizeof(t_main));
    pgr->mlx.mlx = mlx_init();
    if (!pgr->mlx.mlx)
    {
        ft_free(pgr, 2);
        return (NULL);
    }
    pgr->mlx.mlx_win = mlx_new_window(pgr->mlx.mlx, WIDTH, HEIGHT, "CUB3D");
    if (!pgr->mlx.mlx_win)
    {
        ft_free(pgr, 2);
        return (NULL);
    }
	pgr->mlx.img = mlx_new_image(pgr->mlx.mlx, WIDTH, HEIGHT);
	if (!pgr->mlx.img)
	{
		mlx_destroy_window(pgr->mlx.mlx, pgr->mlx.mlx_win);
		mlx_destroy_image(pgr->mlx.mlx, pgr->mlx.img);
		ft_free(pgr, 2);
	}
	return (pgr);
}

void	draw_player(t_main *pgr)
{
	int	color = 0xFFFF00;
	mlx_pixel_put(pgr->mlx.mlx, pgr->mlx.mlx_win, pgr->player_position[0], pgr->player_position[1], color);
}

int	main_aux(char **argv)
{
	(void)argv;
	t_main	*pgr;
	pgr = NULL;
	pgr = init_window(pgr);
	pgr->player_position[0] = 10;
	pgr->player_position[1] = 20;
	draw_player(pgr);
	
	mlx_hook(pgr->mlx.mlx_win, 2, 1L << 0, key_press, pgr->mlx.img);
	mlx_loop(pgr->mlx.mlx);


	return (0);
}

int main(int argc, char **argv)
{
    (void)argc;
    main_aux(argv);

    return 0;
}
