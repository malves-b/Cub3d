#include "../../includes/cub.h"

bool	val_map(t_parse *parse)
{
	int	i;
	//int	j;

	i = 0;
	while(parse->map[i])
	{
		//j = 0;
		//validação se tem uma quebra de linha 
		if(parse->map[i][0] == '\n')
		{
			printf("Error\nInvalid map!\n");
			return false;
		}
		i++;
		//validação de letras
	}
	return (true);
}
    