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
# include "./minilibx-linux/mlx.h"
# include "libft.h"

typedef struct s_main
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img;
}t_main;

/* --------------------------------- PARSING -------------------------------- */


/* ---------------------------------- UTILS --------------------------------- */


/* -------------------------------- INIT GAME ------------------------------- */


#endif