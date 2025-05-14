void	add_map(t_parse *parse, int i)
{
	int j;

	j = i;
	parse->file_lines = 0;
	while(parse->file[j] != NULL)
	{
		parse->file_lines++;
		j++;
	}
	parse->map = malloc(sizeof(char*) * (parse->file_lines + 1));
	if(!parse->map)
	{
		printf("Error\n Memory allocation error\n");
		exit (1) ; ///fazer algo paara exit
	}
	j = 0;
	while(parse->file[i] != NULL)
	{
		parse->map[j] = ft_strdup(parse->file[i++]);
		j++;
	}
	parse->map[j] = NULL;
	//print_map(parse->map);
}