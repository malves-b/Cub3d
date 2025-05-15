/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:06:24 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/22 18:17:12 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	set_north(t_raycasting *raycasting);
void	set_south(t_raycasting *raycasting);
void	set_east(t_raycasting *raycasting);
void	set_west(t_raycasting *raycasting);

/**
 * @brief Function set the vector direction and plane accordingly the start
 * orientation
 */
void	set_direction_vector(char dir, t_raycasting *raycasting)
{
	if (dir == 'N')
		return (set_north(raycasting));
	if (dir == 'S')
		return (set_south(raycasting));
	if (dir == 'E')
		return (set_east(raycasting));
	if (dir == 'W')
		return (set_west(raycasting));
}

void	set_north(t_raycasting *raycasting)
{
	raycasting->dir_x = 0;
	raycasting->dir_y = -1;
	raycasting->plane_vector[0] = 0.66;
	raycasting->plane_vector[1] = 0;
}

void	set_south(t_raycasting *raycasting)
{
	raycasting->dir_x = 0;
	raycasting->dir_y = 1;
	raycasting->plane_vector[0] = -0.66;
	raycasting->plane_vector[1] = 0;
}

void	set_east(t_raycasting *raycasting)
{
	raycasting->dir_x = 1;
	raycasting->dir_y = 0;
	raycasting->plane_vector[0] = 0;
	raycasting->plane_vector[1] = 0.66;
}

void	set_west(t_raycasting *raycasting)
{
	raycasting->dir_x = -1;
	raycasting->dir_y = 0;
	raycasting->plane_vector[0] = 0;
	raycasting->plane_vector[1] = -0.66;
}
