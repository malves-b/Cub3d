/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:36:26 by pemirand          #+#    #+#             */
/*   Updated: 2025/02/13 16:05:15 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		c;

	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	c = (ln % 10) + '0';
	if (ln > 9)
	{
		ft_putnbr_fd(ln / 10, fd);
		write(fd, &c, 1);
	}
	else
		write(fd, &c, 1);
}
