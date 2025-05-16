#include "../../includes/cub.h"

bool	init_overlay(t_ff *ff)
{
	int	i;
	int	j;

	i = 0;
	ff->overlay = malloc(sizeof(int *) * (ff->height + 1));
	if (!ff->overlay)
		return (false);
	while (i < ff->height)
	{
		ff->overlay[i] = malloc(sizeof(int) * (ff->width + 1));
		if (!ff->overlay[i])
			return (false);
		j = 0;
		while (j < ff->width)
			ff->overlay[i][j++] = 0;
		i++;
	}
	return (true);
}

static void	flood_fill(t_ff *ff, int x, int y, bool *invalid)
{
	char	c;

	if (x < 0 || y < 0 || x >= ff->width || y >= ff->height
		|| ff->map_ff[y][x] == '1' || ff->overlay[y][x])
		return ;
	c = ff->map_ff[y][x];
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		*invalid = true;
	ff->overlay[y][x] = 1;
	flood_fill(ff, x + 1, y, invalid);
	flood_fill(ff, x - 1, y, invalid);
	flood_fill(ff, x, y + 1, invalid);
	flood_fill(ff, x, y - 1, invalid);
}

static bool	check_overlay(t_ff *ff)
{
	int	i;

	i = 0;
	while (i < ff->height)
	{
		if (ff->overlay[0][i] != 0 || ff->overlay[ff->height - 1][i] != 0)
		{
			printf("to cansada");
			return (false);
		}
		i++;
	}
	i = 0;
	while (i < ff->height)
	{
		if (ff->overlay[i][0] != 0 || ff->overlay[i][ff->width - 1] != 0)
		{
			printf("aqui");
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	init_ff(t_ff *ff, bool *invalid, t_parse *parse)
{
	if (!init_overlay(ff))
	{
		printf("Error\n Memory allocation error\n");
		free_ff(ff);
		return (false);
	}
	flood_fill(ff, parse->parse_y, parse->parse_x, invalid);
	if (*invalid == true)
	{
		printf("Erro: caractere inválido encontrado no mapa\n");
		free_ff(ff);
		return (false);
	}
	if (!check_overlay(ff))
	{
		printf("Erro: mapa não está fechado\n");
		return (false);
	}
	free_ff(ff);
	return (true);
}

bool	scan_area(t_parse *parse)
{
	t_ff	ff;
	bool	invalid;

	invalid = false;
	ff.map_ff = parse->map;
	ff.height = parse->file_lines;
	ff.width = parse ->max_width;
	if (!init_ff(&ff, &invalid, parse))
		return (false);
	return (true);
}
