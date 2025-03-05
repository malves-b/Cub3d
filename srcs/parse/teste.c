void	teste(char *line, int i, t_parse parse, char *str)
{
	int	len;
	int	j;

	j = 0;
	if (str != NULL)
	{
		printf("Error\n Map is not valid, SO is duplicaated!\n");
		free_parse(parse);
		exit (1);
	}
	while(line[i] != '.')
		i++;
	len = ft_strlen_i(line, i);
	str = malloc(sizeof(char) * len + 1);
	while (line[i] != '\0')
	{
		str[j] = line[i++];
		j++;
	}
	str[j] = '\0';
	printf("ft_is %s\n", str);
}