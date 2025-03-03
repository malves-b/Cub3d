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
	//printf("lines in file %d\n", *file_lines);
}

void	init_file(char *file, t_parse **parse)
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
		(*parse)->file[i] = line;
		i++;
		line = get_next_line(fd);
	}
	//printf("\n\n AQUIIII %d\n\n", i);
	(*parse)->file[i] = NULL;
	free(line);
	close(fd);
}

bool	init_parse_info(t_parse *parse, char *file)
{
	get_number_lines(file, &parse->file_lines);
	parse->file = malloc(sizeof(char *) * parse->file_lines + 1);
	if (!parse->file)
	{
		printf("Error\n Memory allocation error\n");
		return (false); ///fazer algo paara exit
	}
	init_file(file, &parse);
	clean_and_add(&parse);//mudar o nome.
	free_array(&parse->file);
	printf("\n\n");
	printf("%s", parse->no_path);
	printf("%s", parse->so_path);
	printf("%s", parse->we_path);
	printf("%s", parse->ea_path);
	printf("%s", parse->floor_collor);
	printf("%s", parse->ceiling_collor);
	print_map(parse->map);
	//validate_texture(parse);
	//continua fazer a leitura do arquivo para o parse->file
	//usar get_next_line para pegar cada linha já com o malloc.
	return (true);
}