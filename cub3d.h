#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
# include <stdbool.h>


typedef struct s_parse
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor;
	char	*ceiling;
	char	**map;
	char	**file;//ver se precisa
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
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


#endif