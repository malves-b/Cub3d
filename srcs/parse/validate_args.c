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
	// if (!ft_strnstr(map_file, "/map", ft_strlen(map_file)))
	// {
	// 	printf("Please try again with the corrects informations! \n");
	// 	printf("%s <maps/map_file.cub>\n", prog_name);
	// 	return (false);
	// }
	return (true);
}


