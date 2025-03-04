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

	if (!arr || !*arr) // Evita segfault
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
	free(parse->no_path);
	free(parse->so_path);
	free(parse->we_path);
	free(parse->ea_path);
	free(parse->floor_collor);
	free(parse->ceiling_collor);
	free_array(&parse->map);
	free_array(&parse->file);
	free(parse);
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