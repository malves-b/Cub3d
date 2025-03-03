#include "../../includes/cub.h"

void	ft_is_n(char *line, int i, t_parse *parse)
{
	int	len;
	int	j;

	j = 0;
	if (parse->no_path != NULL)
	{
		//frees e exit
		printf("ja tem no\n");
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
		//frees e exit e mensagem de erro 
		printf("ja tem so\n");
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
		//frees e exit e mensagem de erro 
		printf("ja tem we\n");
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
		//frees e exit e mensagem de erro 
		printf("ja tem ea\n");
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
		//frees e exit e mensagem de erro 
		printf("ja tem c\n");
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
		//frees e exit e mensagem de erro 
		printf("ja tem f\n");
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
