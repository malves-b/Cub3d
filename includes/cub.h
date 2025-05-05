/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:14:39 by malves-b          #+#    #+#             */
/*   Updated: 2025/02/13 16:04:08 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB_H
# define CUB_H

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "./minilibx-linux/mlx.h"
# include "libft.h"

typedef struct s_main
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img;
}t_main;

typedef struct s_cub
{
	//struct s_map *s_map;
	//struct s_player *player;
	//truct s_texture *texture;
	struct s_parse *parse;
} t_cub;

/* ----------------------------- PARSING STRUCTS----------------------------- */
typedef struct s_parse
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_collor;//divide em 3 e trandforma em hexa 
	char	*ceiling_collor;
	char	**map;
	char	**file;
	int		file_lines;
	bool	is_valid;
	char	parse_player;
	int		parse_x;
	int		parse_y;
	struct s_cub *cub;
	struct s_player *player;
}	t_parse;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}	t_map;

typedef struct s_player
{
	char	player;
	int		x;
	int		y;
}	t_player;

typedef struct s_texture
{
	
}	t_texture;
/* --------------------------------- PARSING -------------------------------- */
//validate_parse
bool	check_args(int ac, char *map_file, char *prog_name);

//init_parse_struct
void	init_parse_struct(t_parse *parse);

//read_parse_file
void	init_file(char *file, t_parse *parse);
void	get_number_lines(char *file, int *file_lines);
bool	init_parse_info(t_cub *cub, char *file);

//parse textures
void	add_line(char *line, t_parse *parse);
bool	clean_and_add(t_parse *parse);
int		check_line(char *line);

//parse_textures_info
void	set_texture_path(char *line, int i, t_parse *parse, char **str);
void	ft_is_c(char *line, int i, t_parse *parse);
void	ft_is_f(char *line, int i, t_parse *parse);

//utils_parse
int		ft_strlen_i(char *line, int i);
void	print_map(char **file);//depois apagar 
void	free_array(char ***arr);
void	free_parse(t_parse *parse);

//validate_map
bool	val_map(t_parse *parse);


/* ---------------------------------- UTILS --------------------------------- */


/* -------------------------------- INIT GAME ------------------------------- */


#endif