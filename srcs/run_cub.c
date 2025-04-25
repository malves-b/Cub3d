/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:53 by malves-b          #+#    #+#             */
/*   Updated: 2025/04/25 14:47:26 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_component(t_main *pgr, int color, double map_x, double map_y);
void	draw_direction(t_main *pgr);
void	rotate_player(t_raycasting *ray, double angle);

#define ROT_SPEED 0.05

void	check_next_pos(t_main *pgr, double dir_factor)
{
	double	next_x;
	double	next_y;

	next_x = pgr->ray->pp_x + pgr->ray->dir_x * dir_factor;
	next_y = pgr->ray->pp_y + pgr->ray->dir_y * dir_factor;
	if (pgr->map[(int)(next_y + 0.01)][(int)pgr->ray->pp_x] != '1' &&
		pgr->map[(int)(next_y - 0.01)][(int)pgr->ray->pp_x] != '1')
		pgr->ray->pp_y = next_y;
	if (pgr->map[(int)pgr->ray->pp_y][(int)(next_x + 0.01)] != '1' &&
		pgr->map[(int)pgr->ray->pp_y][(int)(next_x - 0.01)] != '1')
		pgr->ray->pp_x = next_x;
}

int	key_press(int keycode, t_main *pgr)
{
	int	pp_x;
	int	pp_y;

	pp_x = (int)pgr->ray->pp_x;
	pp_y = (int)pgr->ray->pp_y;
	if (keycode == KEY_UP)
		check_next_pos(pgr, 0.3);
	if (keycode == KEY_DOWN)
		check_next_pos(pgr, -0.3);
	if (keycode == KEY_LEFT)
		rotate_player(pgr->ray, -ROT_SPEED);
	if (keycode == KEY_RIGHT)
		rotate_player(pgr->ray, ROT_SPEED);
	if (keycode == KEY_ESC)
		exit(ft_free(pgr));
	ft_bzero(pgr->mlx->img_addr, WIDTH * HEIGHT);
	render_frame(pgr);
	mlx_put_image_to_window(pgr->mlx->mlx, pgr->mlx->mlx_win,
		pgr->mlx->img, 0, 0);
	return (1);
}

void	rotate_player(t_raycasting *ray, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->dir_x;
	old_plane_x = ray->plane_vector[0];
	ray->dir_x = ray->dir_x * cos(angle) - ray->dir_y * sin(angle);
	ray->dir_y = old_dir_x * sin(angle) + ray->dir_y * cos(angle);
	ray->plane_vector[0] = ray->plane_vector[0]
		* cos(angle) - ray->plane_vector[1] * sin(angle);
	ray->plane_vector[1] = old_plane_x
		* sin(angle) + ray->plane_vector[1] * cos(angle);
}
