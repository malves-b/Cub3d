#include "../../includes/cub.h"

void	init_parse_struct(t_parse *parse)
{
	//parse = malloc (sizeof(t_parse));
	parse->no_path = NULL;
	parse->so_path = NULL;
	parse->we_path = NULL;
	parse->ea_path = NULL;
	parse->floor_collor = NULL;
	parse->ceiling_collor = NULL;
	parse->file = NULL;
	parse->map = NULL;
	parse->is_valid = false;
	parse->file_lines = 0;
}

