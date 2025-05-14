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
	struct s_map *smap;
	struct s_player *player;
	struct s_texture *texture;
	struct s_parse *parse;
} t_cub;

/* ----------------------------- PARSING STRUCTS----------------------------- */
typedef struct s_parse
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_color;//divide em 3 e trandforma em hexa 
	char	*ceiling_color;
	char	**map;
	char	**file;
	int		file_lines;
	bool	is_valid;
	char	parse_player;
	int		parse_x;
	int		parse_y;
	int		r;
	int		g;
	int		b;
	struct s_cub *cub;
	struct s_map *smap;
	struct s_player *player;
}	t_parse;

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_player
{
	char	player;
	int		x;
	int		y;
}	t_player;

typedef struct s_texture
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_color;
	char	*ceiling_color;
}	t_texture;
/* --------------------------------- PARSING -------------------------------- */
//validate_parse
bool	check_args(int ac, char *map_file, char *prog_name);

//init_struct
void	init_struct(t_cub *cub);

//read_parse_file
bool	init_file(char *file, t_parse *parse);
bool	get_number_lines(char *file, int *file_lines);
bool	init_parse_info(t_cub *cub, char *file);

//parse_map_textures
bool	add_line(char *line, t_parse *parse);
bool	clean_and_add(t_parse *parse);
int		check_line(char *line);

//color_textures_parse
bool	set_texture_path(char *line, int i, t_parse *parse, char **str);
bool	validate_color(char *line, int i, t_parse *parse, char **str);


//void	ft_is_f(char *line, int i, t_parse *parse);
bool	validate_rgb(t_parse *parse, char *rgb);

//utils_parse
int		ft_strlen_i(char *line, int i);
void	print_map(char **file);//depois apagar 
void	free_array(char ***arr);
void	free_parse(t_parse *parse);
void	free_structs(t_cub *cub);

//validate_map
bool	val_map(t_parse *parse);

//populate_structs
void	populate_structs(t_parse *parse, t_cub *cub);
void	copy_player(t_parse *parse, t_player *player);
void	copy_map(char **src, char ***dest);
void	copy_textures(t_parse *parse, t_texture *texture);

//rgb_to_hexa
void	ft_itoa_hex(t_parse *parse, char **str_color);

//utils_textures_color
char	*clean_rgb_string(const char *input);
bool	check_letters(char *str);
int		ft_isspace(char c);

/* ---------------------------------- UTILS --------------------------------- */


/* -------------------------------- INIT GAME ------------------------------- */


#endif