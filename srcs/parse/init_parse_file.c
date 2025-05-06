#include "../../includes/cub.h"

void	get_number_lines(char *file, int *file_lines)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n the file doesn't exist!\n");
		return ;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{ 	
		(*file_lines)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	init_file(char *file, t_parse *parse)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if(fd < 0)
	{
		printf("Error\n the file doesn't exist!\n");
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		parse->file[i] = line;
		i++;
		line = get_next_line(fd);
	}
	parse->file[i] = NULL;
	free(line);
	close(fd);
}

bool	init_parse_info(t_cub *cub, char *file)
{
	cub->parse = malloc (sizeof(t_parse));
	cub->smap = malloc(sizeof(t_map));
	cub->player = malloc(sizeof(t_player));
	cub->texture = malloc(sizeof(t_texture));
	init_parse_struct(cub->parse);
	get_number_lines(file, &cub->parse->file_lines);//verificação se line é menor ou == 0 
	cub->parse->file = malloc(sizeof(char *) * (cub->parse->file_lines + 1));
	if (!cub->parse->file || !cub->parse || !cub->smap)
	{
		printf("Error\n Memory allocation error\n");
		return (false); ///fazer algo paara exit
	}
	init_file(file, cub->parse);
	if(!clean_and_add( cub->parse))
		return (false);
	if(!val_map(cub->parse))
		return (false);
	free_array( &cub->parse->file);
	populate_structs(cub->parse, cub);
	printf("\n\n");
	printf("-parse %s", cub->parse->ceiling_collor);
	free(cub->parse->no_path);
	free(cub->parse->so_path);
	free(cub->parse->we_path);
	free(cub->parse->ea_path);
	free_array(&cub->parse->map);
	print_map(cub->smap->map);
	printf("%c--%d-%d- \n", cub->player->player, cub->player->x,cub->player->y);
	printf("%s", cub->texture->no_path);
	printf("%s", cub->texture->so_path);
	printf("%s", cub->texture->we_path);
	printf("%s",cub->texture->ea_path);

	printf("\n\n");
	//free_parse(cub->parse);
	//validate_texture(parse);
	return (true);
}