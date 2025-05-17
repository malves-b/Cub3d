/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_textures_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:33:12 by jesilva-          #+#    #+#             */
/*   Updated: 2025/05/17 16:33:14 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static bool	check_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ',' && !(str[i] >= '0' && str[i] <= '9'))
		{
			printf("Error\nMap is not valid, color is not valid!\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	set_texture_path(char *line, int i, char **str_struct)
{
	int	len;
	int	j;

	j = 0;
	if (*str_struct != NULL)
	{
		printf("Error\nMap is not valid, textures are duplicaated!\n");
		return (false);
	}
	while (line[i] != '/')
	{
		i++;
	}
	i++;
	remove_newline(line);
	len = ft_strlen_i(line, i);
	*str_struct = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		(*str_struct)[j] = line[i++];
		j++;
	}
	(*str_struct)[j] = '\0';
	return (true);
}

bool	validate_color(char *line, t_parse *parse, char **str_struct)
{
	char	*temp;

	if (*str_struct != NULL)
	{
		printf("Error\nMap is not valid, Color is not valid!\n");
		return (false);
	}
	if (!check_letters(line))
	{
		printf("Error\nMap is not valid, Color is not valid!\n");
		return (false);
	}
	temp = clean_rgb_string(line);
	if (!check_is_digit(temp) || !validate_rgb(parse, temp))
	{
		free(temp);
		return (false);
	}
	ft_itoa_hex(parse, str_struct);
	if (parse->f_or_c == 1)
		parse->hexa_floor = rgb_to_hex(parse);
	else if (parse->f_or_c == 2)
		parse->hexa_ceiling = rgb_to_hex(parse);
	free(temp);
	return (true);
}

bool	validate_rgb(t_parse *parse, char *rgb)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(rgb, ',');
	while (split[i])
		i++;
	if (i != 3)
	{
		printf("Error\nRGB invalid!\n");
		free_array(&split);
		return (false);
	}
	parse->r = ft_atoi(split[0]);
	parse->g = ft_atoi(split[1]);
	parse->b = ft_atoi(split[2]);
	if ((parse->r < 0 || parse->r > 255) || (parse->g < 0 || parse->g > 255)
		|| (parse->b < 0 || parse->b > 255))
	{
		printf("Error\nRGB invalid!\n");
		free_array(&split);
		return (false);
	}
	free_array(&split);
	return (true);
}

int	ft_strlen_i(char *line, int i)
{
	int	j;

	j = 0;
	while (line[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}
