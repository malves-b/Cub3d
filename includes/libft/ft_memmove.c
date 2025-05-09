/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:36:26 by pemirand          #+#    #+#             */
/*   Updated: 2025/02/13 16:05:15 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ps;
	char		*pd;
	size_t		i;

	if (!dest && !src)
		return (dest);
	ps = (char *) src;
	pd = (char *) dest;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			pd[i] = ps[i];
			i++;
		}
	}
	else
	{
		while (n--)
			pd[n] = ps[n];
	}
	return (dest);
}
