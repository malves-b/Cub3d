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
/* --------------------------------- PARSING -------------------------------- */
//validate_parse
bool	check_args(int ac, char *map_file, char *prog_name);
//init_parse_struct
void	init_parse_struct(t_parse *parse);
//read_parse_file
void	init_file(char *file, t_parse **parse);
bool	ft_read_file(t_parse *parse, char *file);
void	get_number_lines(char *file, int *file_lines);
//utils_parse
void	print_map(char **file);//depois apagar 



/* ---------------------------------- UTILS --------------------------------- */


/* -------------------------------- INIT GAME ------------------------------- */


#endif