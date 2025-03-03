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
	struct s_parse *parse;
} t_cub;

/* ----------------------------- PARSING STRUCTS----------------------------- */
typedef struct s_parse
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_collor;
	char	*ceiling_collor;
	char	**map;
	char	**file;
	int		file_lines;//ver se precisa
	bool	is_valid;
	// bool	no;
	// bool	so;
	// bool	we;
	// bool	ea;
	// bool	floor;
	// bool	ceiling; //tiar bool e inicializar os chars a null;
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
/* --------------------------------- PARSING -------------------------------- */
//validate_parse
bool	check_args(int ac, char *map_file, char *prog_name);
//void	validate_texture(t_parse *parse);

//init_parse_struct
void	init_parse_struct(t_parse *parse);

//read_parse_file
void	init_file(char *file, t_parse *parse);
void	get_number_lines(char *file, int *file_lines);
bool	init_parse_info(t_parse *parse, char *file);

//parse textures
void	ft_is_c(char *line, int i, t_parse *parse);
void	ft_is_f(char *line, int i, t_parse *parse);
void	add_line(char *line, t_parse *parse);
void	clean_and_add(t_parse *parse);
int		check_line(char *line);

//parse_textures_info
void ft_is_n(char *line, int i, t_parse *parse);
void ft_is_s(char *line, int i, t_parse *parse);
void ft_is_w(char *line, int i, t_parse *parse);
void ft_is_e(char *line, int i, t_parse *parse);

//utils_parse
int		ft_strlen_i(char *line, int i);
void	print_map(char **file);//depois apagar 
void	free_array(char ***arr);



/* ---------------------------------- UTILS --------------------------------- */


/* -------------------------------- INIT GAME ------------------------------- */


#endif