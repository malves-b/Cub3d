#include "../../includes/cub.h"

bool	is_valid_texture(char *path)
{
	int	len;
	//int fd;

	if (!path)
		return (false);
	len = ft_strlen(path);
	if (path[len - 1] == '\n')
		len--;
	if(len < 4 || strncmp(path + len - 4, ".xpm", 4) != 0)
	//if(ft_strnstr(path, ".xpm", len - 4))
	{
		printf("Error: Texture file must have a .xpm extension!\n");
		return (false);
	}
	// fd = open(path, O_RDONLY);
	// if(fd == -1)
	// {
	// 	perror("Error\nTexture file is not valid");
	// 	return (false);
	// }
	// close(fd);
	return(true);
}

bool	val_textures(t_parse *parse)//colocar em outro arquivo
{
	if(parse->is_valid == true)
	{
		if (!is_valid_texture(parse->no_path))
			return (false);
		if (!is_valid_texture(parse->so_path))
			return (false);
		if (!is_valid_texture(parse->we_path))
			return (false);
		if (!is_valid_texture(parse->ea_path))
			return (false);
		return (true);
	}
	else
		return (false);
}

bool	check_args(int ac ,char *map_file, char *prog_name)
{
	if (ac != 2)
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
