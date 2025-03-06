/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:08:51 by malves-b          #+#    #+#             */
/*   Updated: 2025/03/06 13:08:24 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	*safe_calloc(t_main *pgr, size_t size)
{
	void	*alloc;

	alloc = ft_calloc(size, 1);
	if (!alloc)
	{
		ft_free(pgr, 1);
		ft_putstr_fd("ALLOC ERROR!\n", 2);
		exit (1);
	}
	return (alloc);
}