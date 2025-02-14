#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_parse
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_path;
	char	*ceiling_path;
	char	**map;
	char	**file;
	int		file_lines;//ver se precisa
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
	bool	floor;
	bool	ceiling;
}	t_parse;

typedef struct s_map
{
	char **map;
	int height;
	int width;
}	t_map;

typedef struct s_player
{
	
}	t_player;

typedef struct s_texture
{
	
}	t_texture;

typedef struct s_cub
{
	t_parse *parse;
} t_cub;

#endif