#include "../../includes/cub.h"

static bool check_is_digit(char *str)
{
	int	i;


	i = 0;
	//printf("%s temp CHECK IS DIGIT\n", str);
	while(str[i] != '\n')
	{
		//printf("%c CHECK character is DIGIT\n", str[i]);
		if(str[i] != ',' && !(str[i] > '0' && str[i] < '9'))
		{
			printf("Error\nMap is not valid, color is not valid!\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	set_texture_path(char *line, int i, t_parse *parse, char **str)
{
	int	len;
	int	j;

	(void)parse;
	j = 0;
	if (*str != NULL)
	{
		printf("Error\nMap is not valid, textures are duplicaated!\n");
		return (false);
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
	return (true);
	//printf("parse deu certo? == %s no\n", parse->no_path);
}

bool	validate_color(char *line, int i, t_parse *parse, char **str)
{
	int	len;
	int	j;
	char *temp;
	
	j = 0;
	if (*str != NULL)
	{
		printf("Error\nMap is not valid, Color is not valid!\n");
		// free_parse(parse);
		// free_structs(parse->cub);
		return (false);
	}
	printf("%s line ---", line);
	while(!ft_isdigit(line[i]))//AQUIIIIIIIIIIIIIICRLH
		i++;
	len = ft_strlen_i(line, i);
	temp = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		temp[j] = line[i++];
		j++;
	}
	temp[j] = '\0';
	printf("aaaaaaaaaaaaaaaaaaaaaaaaa\n");
	if(!check_is_digit(temp) || !validate_rgb(parse, temp))
	{
		free(temp);
		return (false);
	}
	ft_itoa_hex(parse, str);
	printf("%s temp_color\n", temp);
	free(temp);
	return (true);
}

bool	validate_rgb(t_parse *parse, char *rgb)
{
	char	**split;
	int		i;
	
	i = 0;
	split = ft_split(rgb, ',');
	while(split[i])
		i++;
	if(i != 3)
	{
		printf("Erro: formato RGB inválido!\n");
		free_array(&split);
		return (false);
	}
	parse->r = ft_atoi(split[0]);
	parse->g = ft_atoi(split[1]);
	parse->b = ft_atoi(split[2]);
//	printf("%i- r\n%i- g\n%i- b\n", parse->r, parse->g,parse->b);
	if((parse->r < 0 && parse->r > 255 )|| (parse->g < 0 && parse->g > 255) || (parse->b < 0 && parse->b > 255))
	{
		printf("Erro: formato RGB inválidoaaaaaaaa!\n");
		free_array(&split);
		return (false);
	}
	free_array(&split);
	return (true);
}
