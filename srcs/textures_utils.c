/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:49:14 by malves-b          #+#    #+#             */
/*   Updated: 2025/05/12 12:49:23 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_image *get_wall_texture(t_main *pgr)
{
    if (pgr->ray->side == 1)
    {
        if (pgr->ray->stepy > 0)
			return (pgr->texture_south);
        else
			return (pgr->texture_north);
    }
    else
    {
        if (pgr->ray->stepx > 0)
			return (pgr->texture_east);
        else
			return (pgr->texture_west);
    }
}

