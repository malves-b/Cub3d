#include "../../includes/cub.h"

void	set_texture_path(char *line, int i, t_parse *parse, char **str)
{
	int	len;
	int	j;

	j = 0;
	if (*str != NULL)
	{
		printf("Error\n Map is not valid, textures are duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	while(line[i] != '.')
	{
		i++;
	}
	len = ft_strlen_i(line, i);
	*str = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		(*str)[j] = line[i++];
		j++;
	}
	(*str)[j] = '\0';
	//printf("parse deu certo? == %s no\n", parse->no_path);
}

void	ft_is_c(char *line, int i, t_parse *parse)
{
	int	len;
	int	j;

	j = 0;
	if (parse->ceiling_color != NULL)
	{
		printf("Error\n Map is not valid, C is duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	while(!ft_isdigit(line[i]))
		i++;
	len = ft_strlen_i(line, i);
	parse->ceiling_color = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		parse->ceiling_color[j] = line[i++];
		j++;
	}
	parse->ceiling_color[j] = '\0';
//	printf("ft_is %s\n", parse->ceiling_color);
}
static bool check_is_digit(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(str[i] != ',' && (str[i] < '0' && str[i] > '9'))
		{
			printf("Error\n Map is not valid, color is not valid!\n");
			return (false);
		}
		i++;
	}
	return (true);
}

void	ft_is_f(char *line, int i, t_parse *parse)
{
	int	len;
	int	j;

	j = 0;
	if (parse->floor_color != NULL)
	{
		printf("Error\n Map is not valid, F is duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	while(!ft_isdigit(line[i]))
		i++;
	len = ft_strlen_i(line, i);
	parse->floor_color = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		parse->floor_color[j] = line[i++];
		j++;
	}
	parse->floor_color[j] = '\0';
	if(!check_is_digit(parse->floor_color) || !validate_rgb(parse, parse->floor_color))
	{
		free_parse(parse);
		exit (1);
	}
	printf("- parse F %s\n", parse->floor_color);
	ft_itoa_hex(parse);
	free(parse->floor_color);
	parse->floor_color = parse->hexa;
	//free(parse->hexa);
	printf(" F hexa %s\n", parse->floor_color);

}

bool	validate_rgb(t_parse *parse, char *rgb)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(rgb, ',');
	while(split[i])
		i++;
	if(i != 3)//pode ser 2 pois começa no 0
	{
		printf("Erro: formato RGB inválido!\n");
		free_array(&split);
		return (false);
	}
	parse->r = ft_atoi(split[0]);
	parse->g = ft_atoi(split[1]);
	parse->b = ft_atoi(split[2]);
	if(parse->r < 0 || parse->r > 255 || parse->g < 0 || parse->g > 255 || parse->b < 0 || parse->b > 255)
	{
		printf("Erro: formato RGB inválido!\n");
		free_array(&split);
		return (false);
	}
	free_array(&split);
	return (true);
}
