#include "../../includes/cub.h"

void print_map(char **file)
{
	int i = 0;

	while (file[i])
	{
		printf("%s", file[i]);
		i++;
	}
}

void	free_array(char ***arr)
{
	int i = 0;

	if (!arr || !*arr)
		return;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	free_parse(t_parse *parse)
{
	if(parse->no_path != NULL)
		free(parse->no_path);
	if(parse->so_path != NULL)
		free(parse->so_path);
	if(parse->we_path != NULL)
		free(parse->we_path);
	if(parse->ea_path != NULL)
		free(parse->ea_path);
	if(parse->floor_color != NULL)
		free(parse->floor_color);
	if(parse->ceiling_color != NULL)
		free(parse->ceiling_color);
	free_array(&parse->map);
	free_array(&parse->file);
	free(parse);
	//if(parse->cub)
	//free(parse->cub);
	//free(parse);
	//init_parse_struct(parse);//evita lixo de memoria
}

int	ft_strlen_i(char *line, int i)
{
	int j;

	j = 0;
	while(line[i] != '\0')
	{
		j++;
		i++;
	}
	return(j);
}