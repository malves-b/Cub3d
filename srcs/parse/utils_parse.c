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