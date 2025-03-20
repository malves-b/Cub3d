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
	init_parse_struct(cub->parse);
	get_number_lines(file, &cub->parse->file_lines);//verificação se line é menor ou == 0 
	cub->parse->file = malloc(sizeof(char *) * (cub->parse->file_lines + 1));
	if (!cub->parse->file || !cub->parse)
	{
		printf("Error\n Memory allocation error\n");
		return (false); ///fazer algo paara exit
	}
	init_file(file, cub->parse);
	if(!clean_and_add( cub->parse))
		return (false);
	if(!val_textures(cub->parse))
		return (false);
	free_array( &cub->parse->file);
	printf("\n\n");
	printf("%s", cub->parse->no_path);
	printf("%s", cub->parse->so_path);
	printf("%s", cub->parse->we_path);
	printf("%s",cub->parse->ea_path);
	printf("%s", cub->parse->floor_collor);
	printf("%s", cub->parse->ceiling_collor);
	print_map( cub->parse->map);
	printf("\n\n");
	//validate_texture(parse);
	return (true);
}