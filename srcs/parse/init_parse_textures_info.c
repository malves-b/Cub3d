#include "../../includes/cub.h"

void	ft_is_n(char *line, int i, t_parse *parse)
{
	int	len;
	int	j;

	j = 0;
	if (parse->no_path != NULL)
	{
		printf("Error\n Map is not valid, NO is duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	len = ft_strlen_i(line, i);
	parse->no_path = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		parse->no_path[j] = line[i++];
		j++;
	}
	parse->no_path[j] = '\0';
	printf("ft_is %s\n", parse->no_path);
}

void	ft_is_s(char *line, int i, t_parse *parse)
{
	int	len;
	int	j;

	j = 0;
	if (parse->so_path != NULL)
	{
		printf("Error\n Map is not valid, SO is duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	len = ft_strlen_i(line, i);
	parse->so_path = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		parse->so_path[j] = line[i++];
		j++;
	}
	parse->so_path[j] = '\0';
	printf("ft_is %s\n", parse->so_path);
}

void	ft_is_w(char *line, int i, t_parse *parse)
{
	int	len;
	int	j;

	j = 0;
	if (parse->we_path != NULL)
	{
		printf("Error\n Map is not valid, WE is duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	len = ft_strlen_i(line, i);
	parse->we_path = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		parse->we_path[j] = line[i++];
		j++;
	}
	parse->we_path[j] = '\0';
	printf("ft_is %s\n", parse->we_path);
}


void	ft_is_e(char *line, int i, t_parse *parse)
{
	int	len;
	int	j;

	j = 0;
	if (parse->ea_path != NULL)
	{
		printf("Error\n Map is not valid, EA is duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	len = ft_strlen_i(line, i);
	parse->ea_path = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		parse->ea_path[j] = line[i++];
		j++;
	}
	parse->ea_path[j] = '\0';
	printf("ft_is %s\n", parse->ea_path);
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
	len = ft_strlen_i(line, i);
	parse->ceiling_collor = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		parse->ceiling_collor[j] = line[i++];
		j++;
	}
	parse->ceiling_collor[j] = '\0';
	printf("ft_is %s\n", parse->ceiling_collor);
}


void	ft_is_f(char *line, int i, t_parse *parse)
{
	int	len;
	int	j;

	j = 0;
	if (parse->floor_collor != NULL)
	{
		printf("Error\n Map is not valid, F is duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	len = ft_strlen_i(line, i);
	parse->floor_collor = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		parse->floor_collor[j] = line[i++];
		j++;
	}
	parse->floor_collor[j] = '\0';
	printf("ft_is %s\n", parse->floor_collor);
}
