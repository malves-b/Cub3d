/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:42:55 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/23 19:02:00 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	init_mlx_aux(t_mlx *mlx_data)
{
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	if (!mlx_data->img)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
		free(mlx_data);
		return (0);
	}
	mlx_data->img_addr = mlx_get_data_addr(
			mlx_data->img,
			&mlx_data->bits_per_pixel,
			&mlx_data->line_length,
			&mlx_data->endian);
	if (!mlx_data->img_addr)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->img);
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
		free(mlx_data);
		return (0);
	}
	return (42);
}

/** @brief Function alloc and start mlx struct */
t_mlx	*init_mlx(void)
{
	t_mlx	*mlx_data;

	mlx_data = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx_data)
		return (NULL);
	ft_memset(mlx_data, 0, sizeof(t_mlx));
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		return (free(mlx_data), NULL);
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!mlx_data->mlx_win)
	{
		free(mlx_data);
		return (NULL);
	}
	if (!init_mlx_aux(mlx_data))
		return (NULL);
	return (mlx_data);
}
