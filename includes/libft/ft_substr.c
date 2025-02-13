/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:36:26 by pemirand          #+#    #+#             */
/*   Updated: 2025/02/13 16:05:15 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	s_len;
	unsigned int	size;
	unsigned int	i;

	s_len = (unsigned int) ft_strlen(s);
	substr = NULL;
	size = 0;
	if (s_len > start)
	{
		if (s_len >= start + (unsigned int) len)
			size = (unsigned int) len;
		else
			size = s_len - start;
	}
	substr = (char *)malloc(sizeof(char) * (size + 1));
	if (!substr)
		return (NULL);
	substr[size] = '\0';
	i = 0;
	while (i++ < size)
		substr[i - 1] = s[start + i - 1];
	return (substr);
}
