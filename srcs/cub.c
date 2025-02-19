/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:10 by malves-b          #+#    #+#             */
/*   Updated: 2025/02/13 16:02:15 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_window(char **argv)
{
	(void)argv;
	t_main	*pgr;

	ft_memset(&pgr, 0, sizeof(pgr));
	pgr->mlx = mlx_init();
	pgr->mlx_win = mlx_new_window(pgr->mlx, 320, 320, "CUB3D");
}

int main(int argc, char **argv)
{
	(void)argc;
	init_window(argv);

	return 0;
}
