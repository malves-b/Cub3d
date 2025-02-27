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

// void	validate_texture(t_parse *parse)
// {
	//int	i;
	//char *temp;
	
	//i = 0;
	//clean_file
	// while(i < parse->file_lines)
	// {
	// 	if(ft_strnstr(parse->file[i], "1111", ft_strlen(parse->file[i])))
	// 	{
	// 		printf("mapaaaaaaaaaaaaaaaaa\n");
	// 		break ;
	// 	}
	//	printf("%s", parse->file[i]);
	//	temp = clean_file(parse->file[i]);
	//	free(parse->file)
	//	i++;
	// }
// }

//varre as linhas isola as linas e remove os espaços e os \n
//validação para se começar com letras, ainda não é mapa 
