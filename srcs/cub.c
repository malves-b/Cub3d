/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:10 by malves-b          #+#    #+#             */
/*   Updated: 2025/02/16 19:44:27 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_window(char **argv)
{
    (void)argv;
    t_main	*pgr;

    pgr = (t_main *)malloc(sizeof(t_main));
    if (!pgr)
        return;
    ft_memset(pgr, 0, sizeof(t_main));
    pgr->mlx = mlx_init();
    if (!pgr->mlx)
    {
        free(pgr);
        return;
    }
    pgr->mlx_win = mlx_new_window(pgr->mlx, 820, 820, "CUB3D");
    if (!pgr->mlx_win)
    {
        free(pgr);
        return;
    }
	mlx_loop(pgr->mlx);
}

int main(int argc, char **argv)
{
    (void)argc;
    init_window(argv);

    return 0;
}
