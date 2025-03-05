#include "../../includes/cub.h"


// void	teste(char *line, int i, t_parse *parse, char *str)
// {
// 	int	len;
// 	int	j;

// 	j = 0;
// 	if (str != NULL)
// 	{
// 		printf("Error\n Map is not valid, SO is duplicaated!\n");
// 		free_parse(parse);
// 		exit (1);
// 	}
// 	while(line[i] != '.')
// 		i++;
// 	len = ft_strlen_i(line, i);
// 	str = malloc(sizeof(char) * len + 1);
// 	while (line[i] != '\0')
// 	{
// 		str[j] = line[i++];
// 		j++;
// 	}
// 	str[j] = '\0';
// 	printf("ft_is %s\n", str);
// }

void	add_line(char *line, t_parse *parse)
{
	int		i;

	i = 0;
	while(line[i] == ' ')//adicionar outros espaços 
		i++;
	if (line[i] == 'N')
		ft_is_n(line, i, parse);
		//teste(line, i, parse, parse->no_path);
	else if (line[i] == 'S')
		ft_is_s(line, i, parse);
	 else if (line[i] == 'W')
		ft_is_w(line, i, parse);
	else if (line[i] == 'E')
		ft_is_e(line, i, parse);
	else if (line[i] == 'F')
		ft_is_f(line, i, parse);
	else if (line[i] == 'C')
		ft_is_c(line, i, parse);
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
			&& parse->ea_path != NULL && parse->floor_collor != NULL 
			&& parse->ceiling_collor != NULL)
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
	parse->map = malloc(sizeof(char*) * (parse->file_lines + 1));
	if(!parse->map)
	{
		printf("Error\n Memory allocation error\n");
		exit (1) ; ///fazer algo paara exit
	}
	j = 0;
	while(parse->file[i] != NULL)
	{
		parse->map[j] = ft_strdup(parse->file[i++]);
		j++;
	}
	parse->map[j] = NULL;
	//print_map(parse->map);
}

bool	clean_and_add(t_parse *parse)
{
	int	i;

	i = 0;
	while(parse->file[i] != NULL)
	{
		if (check_line(parse->file[i]) == 1)//tem
			add_line(parse->file[i], parse);
		else if (check_line(parse->file[i]) == 0)
		{
			if(parse->is_valid == true)
			{
				add_map(parse, i);
				break ;
			}
			else
			{
				printf("Invalid_map\n\n");
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
