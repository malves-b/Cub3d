/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:14:39 by malves-b          #+#    #+#             */
/*   Updated: 2025/03/06 15:39:27 by malves-b         ###   ########.fr       */
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
# include "./minilibx-linux/mlx.h"
# include "libft.h"

# define WIDTH 800
# define HEIGHT 600

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362

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
	t_raycasting	*raycasting;
	char			player_direction;
}	t_main;

/* --------------------------------- PARSING -------------------------------- */


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