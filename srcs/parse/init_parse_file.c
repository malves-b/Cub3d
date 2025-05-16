#include "../../includes/cub.h"

bool	get_number_lines(char *file, int *file_lines)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n the file doesn't exist!\n");
		close(fd);
		return (false);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		(*file_lines)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (true);
}

bool	init_file(char *file, t_parse *parse)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n the file doesn't exist!\n");
		close(fd);
		return (false);
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
	return (true);
}

bool	init_parse_info(t_main *cub, char *file)
{
	init_struct(cub);
	if (!(get_number_lines(file, &cub->parse->file_lines)))
		return (false);
	cub->parse->file = malloc(sizeof(char *) * (cub->parse->file_lines + 1));
	if (!cub->parse->file || !cub->parse || !cub->smap)
	{
		printf("Error\n Memory allocation error\n");
		return (false);
	}
	if (!init_file(file, cub->parse))
		return (false);
	if (!clean_and_add(cub->parse))
		return (false);
	if (!val_map(cub->parse))
		return (false);
	free_array(&cub->parse->file);
	if (!validate_texture(cub->parse))
		return (false);
	if (!scan_area(cub->parse))
		return (false);
	populate_structs(cub->parse, cub);
	printf("\n\n");
	return (true);
}
