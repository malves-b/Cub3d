#include "../../includes/cub.h"

void	free_array(char ***arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	free_parse(t_parse *parse)
{
	if (parse->no_path != NULL)
		free(parse->no_path);
	if (parse->so_path != NULL)
		free(parse->so_path);
	if (parse->we_path != NULL)
		free(parse->we_path);
	if (parse->ea_path != NULL)
		free(parse->ea_path);
	if (parse->floor_color != NULL)
		free(parse->floor_color);
	if (parse->ceiling_color != NULL)
		free(parse->ceiling_color);
	free_array(&parse->map);
	free_array(&parse->file);
	free(parse);
}

void	free_structs(t_main *cub)
{
	if (cub->smap->map != NULL)
		free_array(&cub->smap->map);
	if (cub->texture->no_path != NULL)
		free(cub->texture->no_path);
	if (cub->texture->so_path != NULL)
		free(cub->texture->so_path);
	if (cub->texture->we_path != NULL)
		free(cub->texture->we_path);
	if (cub->texture->ea_path != NULL)
		free(cub->texture->ea_path);
	free(cub->smap);
	free(cub->player);
	free(cub->texture);
}

void	free_ff(t_ff *ff)
{
	int	i;

	i = 0;
	if (ff->overlay)
	{
		while (i < ff->height)
		{
			free(ff->overlay[i]);
			ff->overlay[i] = NULL;
			i++;
		}
	}
	free(ff->overlay);
}

int	ft_exit(t_main *cub)
{
	free_parse(cub->parse);
	free_structs(cub);
	free(cub);
	return (0);
}
