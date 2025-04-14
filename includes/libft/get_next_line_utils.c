/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:50:30 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/14 18:50:32 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_check(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n' || stash[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_get(char *stash, char *temp)
{
	int		i;
	int		j;
	char	*temp_stash;

	i = 0;
	j = 0;
	if (!stash)
	{
		stash = malloc(sizeof(char));
		stash[0] = '\0';
	}
	temp_stash = (char *)malloc(sizeof(char) * ((ft_strlen
					(stash) + ft_strlen(temp)) + 1));
	if (!stash)
		return (NULL);
	while (stash[i] != '\0')
	{
		temp_stash[i] = stash[i];
		i++;
	}
	while (temp[j] != '\0')
		temp_stash[i++] = temp[j++];
	free (stash);
	temp_stash[i] = '\0';
	return (temp_stash);
}