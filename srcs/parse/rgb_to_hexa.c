/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:34:43 by jesilva-          #+#    #+#             */
/*   Updated: 2025/05/17 16:34:45 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	number_to_hex(int nbr, char *hexa, int start)
{
	char	hex_digits[17];

	ft_strlcpy(hex_digits, "0123456789abcdef", 17);
	hexa[start] = hex_digits[nbr / 16];
	hexa[start + 1] = hex_digits[nbr % 16];
}

void	ft_itoa_hex(t_parse *parse, char **dest_color)
{
	char	*str_color;

	str_color = NULL;
	if (str_color != NULL)
	{
		free(*dest_color);
		*dest_color = NULL;
	}
	str_color = malloc(sizeof(char) * (6 +1));
	number_to_hex(parse->r, str_color, 0);
	number_to_hex(parse->g, str_color, 2);
	number_to_hex(parse->b, str_color, 4);
	str_color[6] = '\0';
	*dest_color = str_color;
}

int	rgb_to_hex(t_parse *parse)
{
	return ((parse->r << 16) | (parse->g << 8) | parse->b);
}
