#include "../../includes/cub.h"

bool	val_map(t_parse *parse)
{
	int	x;
	int	y;

	x = 0;
	while(parse->map[x])
	{
		y = 0;
		//validação se tem uma quebra de linha 
		if(parse->map[x][0] == '\0')
		{
			printf("Error\nInvalid map!\n");
			return false;
		}
		while(parse->map[x][y] != '\0')
		{
		//validação de letras
			if((parse->map[x][y] == 'N' || parse->map[x][y] == 'S'
			|| parse->map[x][y] == 'E' || parse->map[x][y] == 'W') && parse->parse_player == '\0')
			{
				parse->parse_x = x;
				parse->parse_y = y;
				parse->parse_player = parse->map[x][y];
			}
			else if(((parse->map[x][y] == 'N' || parse->map[x][y] == 'S'
				|| parse->map[x][y] == 'E' || parse->map[x][y] == 'W') && parse->parse_player != '\0'))
			{
				printf("Error\nInvalid map player is duplicated!\n");
				return false;
			}
			else if(parse->map[x][y] != 'N' && parse->map[x][y] != 'S'
				&& parse->map[x][y] != 'E' && parse->map[x][y] != 'W'
				&& parse->map[x][y] != '0' && parse->map[x][y] != '1' && !ft_isspace(parse->map[x][y]))
			{
				printf("Error\nInvalid map! The map contains invalid characters!\n");
				printf("O CARACTERE É -%c-\n", parse->map[x][y]);
				printf("posição x == %i y == %i\n", x, y);
				return false;
			}
			y++;
		}
		x++;
	}
	if(!parse->parse_player)
	{
		printf("Error\nInvalid map player, player not found!\n");
		return (false);
	}
	return (true);
}
