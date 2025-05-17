/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesilva- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:34:07 by jesilva-          #+#    #+#             */
/*   Updated: 2025/05/17 16:34:10 by jesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

bool	add_line(char *line, t_parse *parse)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (line[i] == 'N')
		return (set_texture_path(line, i, &parse->no_path));
	else if (line[i] == 'S')
		return (set_texture_path(line, i, &parse->so_path));
	else if (line[i] == 'W')
		return (set_texture_path(line, i, &parse->we_path));
	else if (line[i] == 'E')
		return (set_texture_path(line, i, &parse->ea_path));
	else if (line[i] == 'F')
	{
		parse->f_or_c = 1;
		return (validate_color(line, parse, &parse->floor_color));
	}
	else if (line[i] == 'C')
	{
		parse->f_or_c = 2;
		return (validate_color(line, parse, &parse->ceiling_color));
	}
	printf("Error!\nInvalid texture or color\n");
	return (false);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		return (2);
	while (line[i] != '\0')
	{
		if (line[i] == '1')
			return (0);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
		{
			return (1);
		}
		i++;
	}
	return (3);
}

void	add_map(t_parse *parse, int i)
{
	int	j;

	j = i;
	parse->file_lines = 0;
	while (parse->file[j] != NULL)
	{
		parse->file_lines++;
		j++;
	}
	parse->temp_map = malloc(sizeof(char *) * (parse->file_lines + 1));
	if (!parse->temp_map)
	{
		printf("Error\nMemory allocation error\n");
		exit (1);
	}
	j = 0;
	while (parse->file[i] != NULL)
	{
		remove_newline(parse->file[i]);
		parse->temp_map[j] = ft_strdup(parse->file[i++]);
		j++;
	}
	parse->temp_map[j] = NULL;
	parse->map = make_rectangular(parse->temp_map, parse->file_lines, parse);
	free_array(&parse->temp_map);
}

static bool	final_check_map(t_parse *parse, int i)
{
	if (parse->is_valid == true)
	{
		add_map(parse, i);
		validate_map(parse);
		return (true);
	}
	else
		exit_map_message(parse->cub);
	return (false);
}

bool	clean_and_add(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->file[i] != NULL)
	{
		if (check_line(parse->file[i]) == 1)
		{
			if (!add_line(parse->file[i], parse))
				return (false);
		}
		else if (check_line(parse->file[i]) == 0)
		{
			if (final_check_map(parse, i))
				break ;
		}
		else if (check_line(parse->file[i]) == 3)
			exit_map_message(parse->cub);
		check_texture_is_valid(parse);
		i++;
	}
	return (true);
}
