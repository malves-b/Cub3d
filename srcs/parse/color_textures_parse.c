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
	if (parse->ceiling_collor != NULL)
	{
		printf("Error\n Map is not valid, C is duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	while(!ft_isdigit(line[i]))
		i++;
	len = ft_strlen_i(line, i);
	parse->ceiling_collor = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		parse->ceiling_collor[j] = line[i++];
		j++;
	}
	parse->ceiling_collor[j] = '\0';
//	printf("ft_is %s\n", parse->ceiling_collor);
}

void	ft_is_f(char *line, int i, t_parse *parse)
{
	int	len;
	int	j;

	j = 0;
	if (parse->floor_collor != NULL)
	{
		printf("Error\n Map is not valid, C is duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	while(!ft_isdigit(line[i]))
		i++;
	len = ft_strlen_i(line, i);
	parse->floor_collor = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		parse->floor_collor[j] = line[i++];
		j++;
	}
	parse->floor_collor[j] = '\0';
//	printf("ft_is %s\n", parse->ceiling_collor);
}

// bool	 validate_rgb(t_parse *parse, char *rgb)
// {
// 	char	**split;
// 	int		i;

// 	i = 0;
// 	split = ft_split(rgb, ',');
// 	while(split[i])
// 		i++;
// 	if(i != 3)//pode ser 2 pois começa no 0
// 	{
// 		printf("Erro: formato RGB inválido!\n");
// 		free_array(split);
// 		return (false);
// 	}
// 	parse->r = ft_atoi(split[0]);
// 	parse->g = ft_atoi(split[1]);
// 	parse->b = ft_atoi(split[2]);
// 	if(parse->r < 0 || parse->r > 255 || parse->g < 0 || parse->g > 255 || parse->b < 0 || parse->b > 255)
// 	{
// 		printf("Erro: formato RGB inválido!\n");
// 		free_array(split);
// 		return (false);
// 	}
// 	free_array(split);
// }
