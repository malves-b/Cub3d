#include "../../includes/cub.h"

void	ft_is_c(char *line, int i, t_parse **parse)
{
	int	len;
	int	j;

	j = 0;
	if((*parse)->ceiling_collor != NULL)
	{
		//frees e exit
		printf("ja tem f\n");
		exit (1);
	}
	len = ft_strlen_i(line, i);
	(*parse)->ceiling_collor = malloc(sizeof(char) * len + 1);
	while(line[i] != '\0')
	{
		(*parse)->ceiling_collor[j] = line[i++];
		j++;
	}
	(*parse)->ceiling_collor[j] = '\0';
	printf("ft_is %s\n", (*parse)->ceiling_collor);
}


void	ft_is_f(char *line, int i, t_parse **parse)
{
	int	len;
	int	j;

	j = 0;
	if((*parse)->floor_collor != NULL)
	{
		//frees e exit
		printf("ja tem f\n");
		exit (1);
	}
	len = ft_strlen_i(line, i);
	(*parse)->floor_collor = malloc(sizeof(char) * len + 1);
	while(line[i] != '\0')
	{
		(*parse)->floor_collor[j] = line[i++];
		j++;
	}
	(*parse)->floor_collor[j] = '\0';
	printf("ft_is %s\n", (*parse)->floor_collor);
}

void	add_line(char *line, t_parse **parse)
{
	int		i;

	i = 0;
	while(line[i] == ' ')//adicionar outros espaços 
		i++;
	if (line[i] == 'N')
		ft_is_n(line, i, parse);
	else if (line[i] == 'S')
		ft_is_s(line, i, parse);
	 else if (line[i] == 'W')
		ft_is_w(line, i, parse);
	else if (line[i] == 'E')
		ft_is_e(line, i, parse);
	else if (line[i] == 'F')
		ft_is_f(line, i, parse);
	else if (line[i] == 'C')
		ft_is_c(line, i, parse);
}
int	check_line(char *line)
{
	int	i;

	i = 0;
	if(line[0] == '\n')
		return 2;
	while(line[i] != '\0')
	{
		if(line[i] == 1)
			return (0);

		if(line[i] == 'N' || line[i] == 'S' || line[i] == 'W' 
			|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C')
		{
			return (1);
		}
		i++;
	}
	return (3);
}


void	clean_and_add(t_parse **parse)
{
	int	i;

	i = 0;
	while((*parse)->file[i] != NULL)
	{
		if(check_line((*parse)->file[i]) == 1)//tem
			add_line((*parse)->file[i], parse);
		else if (check_line((*parse)->file[i]) == 0)
		{
			//if((*parse)->is_valid == true)
			//{
				//adiciona o mapa em parse->map
			//}
			//else
			//{
				//invalid_map
				//error message (IDEIA fazer uma função para mensagem de erro personalizada)
			printf("mapa\n");
			return ;
		}
		i++;
	}
}
