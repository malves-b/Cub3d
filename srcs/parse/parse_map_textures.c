#include "../../includes/cub.h"

bool	add_line(char *line, t_parse *parse)
{
	int		i;

	i = 0;
	while(line[i] == ' '  || (line[i] >= 9 && line[i] <= 13))//adicionar outros espaços 
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
		return 2;
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

void	check_is_valid(t_parse *parse)
{
	if (parse->no_path != NULL && parse->so_path != NULL && parse->we_path != NULL 
			&& parse->ea_path != NULL && parse->floor_color != NULL 
			&& parse->ceiling_color != NULL)
	{
		parse->is_valid = true;
	}
}

void	add_map(t_parse *parse, int i)
{
	int j;

	j = i;
	parse->file_lines = 0;
	while(parse->file[j] != NULL)
	{
		parse->file_lines++;
		j++;
	}
	parse->temp_map = malloc(sizeof(char*) * (parse->file_lines + 1));
	if(!parse->temp_map)
	{
		printf("Error\n Memory allocation error\n");
		exit (1) ; ///fazer algo paara exit
	}
	j = 0;
	while(parse->file[i] != NULL)
	{
		remove_newline(parse->file[i]);
		parse->temp_map[j] = ft_strdup(parse->file[i++]);
		j++;
	}
	parse->temp_map[j] = NULL;
	parse->map = make_rectangular(parse->temp_map, parse->file_lines, parse);
	free_array(&parse->temp_map);
}

bool	clean_and_add(t_parse *parse)
{
	int	i;

	i = 0;
	while(parse->file[i] != NULL)
	{
		if (check_line(parse->file[i]) == 1)//tem
		{
			if(!add_line(parse->file[i], parse))
				return (false);
		}
		else if (check_line(parse->file[i]) == 0)
		{
			if(parse->is_valid == true)
			{
				add_map(parse, i);
				if(parse->map == NULL)
				{
					printf("Error\nIvalid map!\n");
					return (false);
				}
				break ;
			}
			else
			{
				printf("Invalid_map\n");
				//free_parse(parse);
				//ENCONTRAR FORMAS DE DAR FREE NO CUBO(OU RETORNA PARA A MAIN)
				//error message (IDEIA fazer uma função para mensagem de erro personalizada)
				return (false);
			}
		}
		check_is_valid(parse);
		i++;
	}
	return (true);
}
