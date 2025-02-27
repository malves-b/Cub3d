#include "../../includes/cub.h"

void ft_is_n(char *line, int i, t_parse **parse)
{
	int	len;
	int	j;

	j = 0;
	len = ft_strlen_i(line, i);
	(*parse)->no_path = malloc(sizeof(char) * len + 1);
	while(line[i] != '\0')
	{
		(*parse)->no_path[j] = line[i++];
		j++;
	}
	(*parse)->no_path[j] = '\0';
	printf("ft_is %s\n", (*parse)->no_path);
}

void ft_is_s(char *line, int i, t_parse **parse)
{
	int	len;
	int	j;

	j = 0;
	len = ft_strlen_i(line, i);
	(*parse)->so_path = malloc(sizeof(char) * len + 1);
	while(line[i] != '\0')
	{
		(*parse)->so_path[j] = line[i++];
		j++;
	}
	(*parse)->so_path[j] = '\0';
	printf("ft_is %s\n", (*parse)->so_path);
}

void ft_is_w(char *line, int i, t_parse **parse)
{
	int	len;
	int	j;

	j = 0;
	len = ft_strlen_i(line, i);
	(*parse)->we_path = malloc(sizeof(char) * len + 1);
	while(line[i] != '\0')
	{
		(*parse)->we_path[j] = line[i++];
		j++;
	}
	(*parse)->we_path[j] = '\0';
	printf("ft_is %s\n", (*parse)->we_path);
}


void ft_is_e(char *line, int i, t_parse **parse)
{
	int	len;
	int	j;

	j = 0;
	len = ft_strlen_i(line, i);
	(*parse)->ea_path = malloc(sizeof(char) * len + 1);
	while(line[i] != '\0')
	{
		(*parse)->ea_path[j] = line[i++];
		j++;
	}
	(*parse)->ea_path[j] = '\0';
	printf("ft_is %s\n", (*parse)->ea_path);
}