/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:14:39 by malves-b          #+#    #+#             */
/*   Updated: 2025/05/09 16:10:24 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "./minilibx-linux/mlx.h"
# include "libft.h"

# define WIDTH 800
# define HEIGHT 600

# define MOVE_SPEED 0.3
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362

/* ----- COLORS -----*/

# define COLOR_SKY		0x87CEEB
# define COLOR_FLOOR	0x333333
# define RED			0xFF0000
# define RED_LIGHT		0xFF6666
# define BROWN			0x8B4513
# define GRAY			0x808080
# define GREEN			0x08000
# define YELLOW			0xFFFF00

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
typedef struct s_main	t_main;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_raycasting
{
	char	start_dir;
	int		map_position_x;
	int		map_position_y;
	double	pp_x;
	double	pp_y;
	double	next_pos_x;
	double	next_pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_vector[2];
	double	sidedistx;
	double	sidedisty;
	double	dltdistx;
	double	dltdisty;
	double	prp_walldst;
	int		stepx;
	int		stepy;
	int		hit_wall;
	int		side;
	// double	wall_x;/*-----*/
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
	t_raycasting	*ray; //raycasting
	t_image			*texture_north;
	t_image			*texture_south;
	t_image			*texture_east;
	t_image			*texture_west;
}	t_main;

/* --------------------------------- TEXTURE -------------------------------- */

int	ft_init_textures(t_main *pgr);

/* --------------------------------- PARSING -------------------------------- */
//validate_parse
bool				check_args(int ac, char *map_file, char *prog_name);
void				validate_texture(t_parse *parse);
void				init_parse_struct(t_parse *parse);
void				init_file(char *file, t_parse **parse);
bool				ft_read_file(t_parse *parse, char *file);
void				get_number_lines(char *file, int *file_lines);
//utils_parse
void				print_map(char **file);//depois apagar 

/* ---------------------------------- UTILS --------------------------------- */

int					ft_free(t_main *pgr);
void				*safe_calloc(t_main *pgr, size_t size);
double				has_decimal(double nbr);
void				my_put_pixel(t_mlx *mlx, int x, int y, int color);
int					close_program(t_main *pgr);

/* ------------------------------- RAYCASTING ------------------------------- */

int					key_press(int keycode, t_main *pgr);
void				set_direction_vector(char dir, t_raycasting *raycasting);
void				set_player_position(t_raycasting *raycasting, char **map);
void				draw_player(t_main *pgr);
void				draw_map(t_main *pgr);
void				my_put_pixel(t_mlx *mlx, int x, int y, int color);
void				render_frame(t_main *pgr);//TEST
void				draw_background(t_main *pgr);
t_raycasting		*init_raycasting(t_main *pgr);

/* -------------------------------- INIT GAME ------------------------------- */

t_mlx				*init_mlx(void);

#endif