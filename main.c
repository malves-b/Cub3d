#include "cub3d.h"

bool	check_av(char *map_file, char *prog_name)
{
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

void init_parse_struct(t_parse *parse)
{
	parse->no = false;
	parse->so = false;
	parse->we = false;
	parse->ea = false;
	parse->floor = false;
	parse->ceiling = false;
}

int	main(int ac, char **av)
{
	t_cub *cub;
	if(ac != 2)
	{
		printf("Please try again with the corrects informations! \n");
		printf("%s <maps/map_file.cub>\n", av[0]);
		return (1);
	}
	if(!check_av(av[1], av[0]))
		return (1);
	cub = malloc (sizeof(t_cub));
	if(!cub)
		retrun (1);
	init_parse_stuct(cub->parse);
	//readmap guardar em algum lugar
	//fazer a validadação
}