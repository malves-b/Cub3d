/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:14:39 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/14 19:08:12 by malves-b         ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 600

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362

/* --------------------------------- PARSING -------------------------------- */

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

/*--------------------------------------------------- */

typedef struct s_raycasting
{
	int		map_position[2];// [0] = x , [1] = y
	double	player_position[2];
	double	direction[2];
	double	plane_vector[2];
}	t_raycasting;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	void	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_main
{
	char			**map;
	t_mlx			*mlx;
	t_parse			*parse; /*---- */
	t_raycasting	*raycasting;
	char			player_direction;
}	t_main;


/* --------------------------------- PARSING -------------------------------- */
//validate_parse
bool	check_args(int ac, char *map_file, char *prog_name);
bool	is_valid_texture(char *path);
bool	val_textures(t_parse *parse);

//init_parse_struct
void	init_parse_struct(t_parse *parse);

//read_parse_file
void	init_file(char *file, t_parse **parse);
void	get_number_lines(char *file, int *file_lines);
bool	init_parse_info(t_main *cub, char *file);

//parse textures
void	add_line(char *line, t_parse *parse);
bool	clean_and_add(t_parse *parse);
int		check_line(char *line);
void	validate_texture(t_parse *parse);

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

void	ft_free(t_main *pgr, int flag);
void	*safe_calloc(t_main *pgr, size_t size);

/* ------------------------------- RAYCASTING ------------------------------- */

t_raycasting	*init_raycasting(t_main *pgr);
void			set_direction_vector(char dir, t_raycasting *raycasting);
void			set_player_position(t_raycasting *raycasting, char **map);


/* -------------------------------- INIT GAME ------------------------------- */

t_mlx	*init_mlx(void);

#endif