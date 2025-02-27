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
	printf("\n\nTESTEEEEEEEEE %s \n\n", (*parse)->no_path);
}