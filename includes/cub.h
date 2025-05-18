/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:14:39 by malves-b          #+#    #+#             */
/*   Updated: 2025/05/18 16:44:38 by malves-b         ###   ########.fr       */
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

/* ----------------------------- PARSING STRUCTS----------------------------- */

typedef struct s_parse
{
	struct s_main		*cub;
	struct s_map		*smap;
	struct s_player		*player;
	struct s_flood		*ff;
	//struct s_texture	*texture;
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	char				*floor_color;
	char				*ceiling_color;
	char				**map;
	char				**temp_map;
	char				**file;
	int					file_lines;
	int					max_width;
	bool				is_valid;
	char				parse_player;
	int					parse_x;
	int					parse_y;
	int					r;
	int					g;
	int					b;
	int					hexa_floor;
	int					hexa_ceiling;
	int					f_or_c;
}	t_parse;

typedef struct s_ff
{
	struct s_cub		*cub;
	char				**map_ff;
	int					**overlay;
	int					width;
	int					height;
}	t_ff;

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
	int		floor_color;
	int		ceiling_color;
}	t_texture;

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
	double	wall_x;//draw_wall
	double	step;//draw_wall
	double	tex_pos;//draw_wall
	int		tex_x;//draw_wall
	int		tex_y;//draw_wall
	int		line_height;
	int		draw_start;
	int		draw_end;
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
	t_mlx				*mlx;
	t_parse				*parse; /*---- */
	t_raycasting		*ray; //raycasting
	t_image				*texture_north;
	t_image				*texture_south;
	t_image				*texture_east;
	t_image				*texture_west;
	struct s_ff			*ff;
	struct s_map		*smap;
	struct s_player		*player;
	struct s_texture	*texture;

}	t_main;

/* --------------------------------- TEXTURE -------------------------------- */

int					ft_init_textures(t_main *pgr);
t_image				*get_wall_texture(t_main *pgr);
void				calc_x(t_main *pgr, double dir_x, double dir_y, int t_wdth);

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

/* --------------------------------- PARSING -------------------------------- */

//validate_parse
bool				check_args(int ac, char *map_file, char *prog_name);

//init_struct
void				init_struct(t_main *cub);

//read_parse_file
bool				init_file(char *file, t_parse *parse);
bool				get_number_lines(char *file, int *file_lines);
bool				init_parse_info(t_main *cub, char *file);

//parse_map_textures
bool				add_line(char *line, t_parse *parse);
bool				clean_and_add(t_parse *parse);
int					check_line(char *line);

//color_textures_parse
bool				set_texture_path(char *line, int i, char **str);
bool				validate_color(char *line, t_parse *parse, char **str);
bool				validate_rgb(t_parse *parse, char *rgb);
int					ft_strlen_i(char *line, int i);

//free_parse
void				free_array(char ***arr);
void				free_parse(t_parse *parse);
void				free_structs(t_main *cub);
int					ft_exit(t_main *cub);
void				free_ff(t_ff *ff);

//validate_map
bool				val_map(t_parse *parse);
void				exit_map_message(t_main *cub);
void				validate_map(t_parse *parse);

//populate_structs
void				populate_structs(t_parse *parse, t_main *cub);
void				copy_player(t_parse *parse, t_player *player);
void				copy_map(char **src, char ***dest);
void				copy_textures(t_parse *parse, t_texture *texture);

//validate_textures
bool				validate_path_texture(t_parse *parse);

//rgb_to_hexa
void				ft_itoa_hex(t_parse *parse, char **str_color);
int					rgb_to_hex(t_parse *parse);

//utils_textures_color
char				*clean_rgb_string(const char *input);
bool				check_letters(char *str);
int					ft_isspace(char c);

//utils_map
char				**make_rectangular(char **map, int height, t_parse *parse);
void				remove_newline(char *str);
void				check_texture_is_valid(t_parse *parse);

//flood_fill
bool				scan_area(t_parse *parse);

#endif
