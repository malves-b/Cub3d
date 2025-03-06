/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:03:48 by malves-b          #+#    #+#             */
/*   Updated: 2025/03/06 15:41:08 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_raycasting	*init_raycasting(t_main *pgr)
{
	t_raycasting	*raycasting;

	raycasting = safe_calloc(pgr, sizeof(t_raycasting));
	set_player_position(raycasting, pgr->map);
	set_direction_vector(pgr->player_direction, raycasting);
	return (raycasting);
}