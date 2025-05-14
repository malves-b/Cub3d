#include "../../includes/cub.h"

void remove_newline(char *str)
{
	int len = ft_strlen(str);

	// Verifica se o último caractere é um '\n' e o remove
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

static int get_max_width(char **map, int height, t_parse *parse)
{
	int i;
	int len;

	len= 0;
	i = 0;
	while(i < height)
	{
		len = ft_strlen(map[i]);
		if(len > parse->max_width)
			parse->max_width = len;
		i++;
	}
	return (parse->max_width);
}

char **make_rectangular(char **map, int height, t_parse *parse)
{
	int	i;
	int j;
	char **map_rec;

	i = 0;
	parse->max_width = get_max_width(map, height, parse);
	map_rec = ft_calloc(sizeof(char *) , (height + 1));
	if (!map_rec)
		return (NULL);
	while(i < height)
	{
		j = 0;
		if(map[i][j] == '\0')
		{
			free_array(&map_rec);
			return NULL;
		}
		map_rec[i] = malloc(sizeof(char) * (parse->max_width + 1));
		if (!map_rec[i])
			return (NULL);
		while(map[i][j])
		{
			map_rec[i][j] = map[i][j];
			j++;
		}
		while(j < parse->max_width)
		map_rec[i][j++] = ' ';
		map_rec[i][j] = '\0';
		i++;
	}
	map_rec[height] = NULL;
	return (map_rec);
}
