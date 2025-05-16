#include "../../includes/cub.h"

void print_map(char **file)
{
	int i = 0;

	while (file[i])
	{
		printf("%s\n", file[i]);
		i++;
	}
}

void	free_array(char ***arr)
{
	int i = 0;

	if (!arr || !*arr)
		return;
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
	if(parse->no_path != NULL)
		free(parse->no_path);
	if(parse->so_path != NULL)
		free(parse->so_path);
	if(parse->we_path != NULL)
		free(parse->we_path);
	if(parse->ea_path != NULL)
		free(parse->ea_path);
	if(parse->floor_color != NULL)
		free(parse->floor_color);
	if(parse->ceiling_color != NULL)
		free(parse->ceiling_color);
	free_array(&parse->map);
	free_array(&parse->file);
	free(parse);
	//if(parse->cub)
	//free(parse->cub);
	//free(parse);
	//init_parse_struct(parse);//evita lixo de memoria
}

void	free_structs(t_main *cub)
{
	if(cub->smap->map != NULL)
		free_array(&cub->smap->map);
	if(cub->texture->no_path != NULL)
		free(cub->texture->no_path);
	if(cub->texture->so_path != NULL)
		free(cub->texture->so_path);
	if(cub->texture->we_path != NULL)
		free(cub->texture->we_path);
	if(cub->texture->ea_path != NULL)
		free(cub->texture->ea_path);
	//if(cub->texture->floor_color != NULL)
	//	free(cub->texture->floor_color);
//	if(cub->texture->ceiling_color != NULL)
//		free(cub->texture->ceiling_color);
	free(cub->smap);
	free(cub->player);
	free(cub->texture);
}
void	free_int_array(t_ff *ff)
{
	int i;
	
	i = 0;
	if(ff->overlay)
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
void	free_ff(t_ff *ff)
{
	//free_array(&ff->overlay);
	free_int_array(ff);
	//free(ff);
}

int ft_exit(t_main *cub)
{
	//free_ff(cub->ff);
	free_parse(cub->parse);
	free_structs(cub);
	free(cub);
	return (1);
}

int	ft_strlen_i(char *line, int i)
{
	int j;

	j = 0;
	while(line[i] != '\0')
	{
		j++;
		i++;
	}
	return(j);
}

