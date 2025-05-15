/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:08:51 by malves-b          #+#    #+#             */
/*   Updated: 2025/05/15 10:58:54 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	close_program(t_main *pgr)
{
	exit(ft_free(pgr));
}

void	my_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	offset;

	offset = (y * mlx->line_length) + (x * (mlx->bits_per_pixel / 8));
	*((unsigned int *)(mlx->img_addr + offset)) = color;
}

double	has_decimal(double nbr)
{
	double	i;

	return (modf(nbr, &i) > 0.001);
}

void	*safe_calloc(t_main *pgr, size_t size)
{
	void	*alloc;

	alloc = ft_calloc(size, 1);
	if (!alloc)
	{
		ft_free(pgr);
		ft_putstr_fd("ALLOC ERROR!\n", 2);
		exit (1);
	}
	return (alloc);
}
