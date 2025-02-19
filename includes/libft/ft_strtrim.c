/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:46:33 by pemirand          #+#    #+#             */
/*   Updated: 2025/02/13 16:05:15 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		head;
	int		tail;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	tail = ft_strlen(s1);
	head = 0;
	if (tail > 0)
	{
		tail--;
		while (s1[head] && ft_strchr(set, s1[head]))
			head++;
		while (tail >= 0 && s1[tail] && ft_strchr(set, s1[tail]))
			tail--;
	}
	return (ft_substr(s1, head, tail - head + 1));
}
