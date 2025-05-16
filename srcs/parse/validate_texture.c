#include "../../includes/cub.h"

static bool	check_format(char *texture_path)
{
	if (!ft_strnstr(texture_path, ".xpm", ft_strlen(texture_path)))
	{
		printf("Please try again with the corrects informations! \n");
		printf("Texture is not valid\n");
		return (false);
	}
	return (true);
}

static bool	check_texture_format(t_parse *parse)
{
	if (!check_format(parse->no_path))
		return (false);
	if (!check_format(parse->so_path))
		return (false);
	if (!check_format(parse->we_path))
		return (false);
	if (!check_format(parse->ea_path))
		return (false);
	return (true);
}

static bool	check_is_valid(char *texture)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n the texture doesn't exist!\n");
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

static bool	check_texture_valid(t_parse *parse)
{
	if (!check_is_valid(parse->no_path))
		return (false);
	if (!check_is_valid(parse->so_path))
		return (false);
	if (!check_is_valid(parse->we_path))
		return (false);
	if (!check_is_valid(parse->ea_path))
		return (false);
	return (true);
}

bool	validate_texture(t_parse *parse)
{
	if (!check_texture_format(parse))
		return (false);
	check_texture_valid(parse);
	return (true);
}
