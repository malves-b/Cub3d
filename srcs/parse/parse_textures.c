#include "../../includes/cub.h"

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

		if(line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			return (1);
		}
		i++;
	}
	return (3);
}

void	add_line(char *line, t_parse **parse)
{
	int		i;

	i = 0;
	while(line[i] == ' ')//adicionar outros espaços 
		i++;
	if (line[i] == 'N')
		ft_is_n(line, i, parse);
	// else if (line[i] == 'S')
	// 	f_is_n(line, i, parse);
	// else if (line[i] == 'W')
	// 	f_is_n(line, i, parse);
	// else if (line[i] == 'E')
	// 	f_is_n(line, i, parse);
	// else if (line[i] == 'F')
	// 	f_is_n(line, i, parse);
	// else if (line[i] == 'C')
	// 	f_is_n(line, i, parse);
}

void	clean_and_add(t_parse **parse)
{
	int	i;

	i = 0;
	while((*parse)->file[i] != NULL)
	{
		if(check_line((*parse)->file[i]) == 1)//tem
		{
			printf("achou letras validas\n");
			add_line((*parse)->file[i], parse);
		}
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
	
		else if (check_line((*parse)->file[i]) == 3)
		{
			printf("erroooouuu\n"); //função para frees e exit de erros
			return ;
		}
		i++;
	}
}
