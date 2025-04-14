#include "../../includes/cub.h"

bool	check_args(int ac ,char *map_file, char *prog_name)
{
    if(ac != 2)
	{
		printf("Error\nPlease try again with the corrects informations! \n");
		printf("%s <maps/map_file.cub>\n", prog_name);
		return (false);
	}
	if (!ft_strnstr(map_file, ".cub", ft_strlen(map_file)))
	{
		printf("Please try again with the corrects informations! \n");
		printf("%s <maps/map_file.cub>\n", prog_name);
		return (false);
	}
	if (!ft_strnstr(map_file, "/map", ft_strlen(map_file)))
	{
		printf("Please try again with the corrects informations! \n");
		printf("%s <maps/map_file.cub>\n", prog_name);
		return (false);
	}
	return (true);
}

void	validate_texture(t_parse *parse)
{
	int	i;
	
	i = 0;
	while(i < parse->file_lines)
	{
		if(ft_strnstr(parse->file[i], "1111", ft_strlen(parse->file[i])))
		{
			printf("mapaaaaaaaaaaaaaaaaa\n");
			break ;
		}
		printf("%s", parse->file[i]);
//		(printf("next %d\n", i));
		i++;
	}
}