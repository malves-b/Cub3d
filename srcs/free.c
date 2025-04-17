/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:39:03 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/17 18:46:16 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_mlx_struct(t_mlx *mlx);

/**
 * @brief Function free memories accordingly the flag
 * @param flag 1 = free all program memory
 * @param flag 2 = free only mlx struct
 */
void	ft_free(t_main *pgr)
{
	free_mlx_struct(pgr->mlx);
	free (pgr->mlx);
	free (pgr->ray);
	free (pgr->parse);
	free (pgr->map);
	free (pgr);
}

void free_mlx_struct(t_mlx *mlx)
{
    if (mlx->img)
    {
        mlx_destroy_image(mlx->mlx, mlx->img);
        mlx->img = NULL;
    }
    if (mlx->mlx_win)
    {
        mlx_destroy_window(mlx->mlx, mlx->mlx_win);
        mlx->mlx_win = NULL;
    }
    if (mlx->mlx)
    {
        mlx_destroy_display(mlx->mlx);
        free(mlx->mlx);
        mlx->mlx = NULL;
    }
}
