/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:33:10 by malves-b          #+#    #+#             */
/*   Updated: 2025/02/13 16:02:15 by malves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// void	init_window(char **argv)
// {
// 	(void)argv;
// 	t_main	*pgr;

// 	ft_memset(&pgr, 0, sizeof(pgr));
// 	pgr->mlx = mlx_init();
// 	pgr->mlx_win = mlx_new_window(pgr->mlx, 320, 320, "CUB3D");
// }

int	main(int argc, char **argv)
{
	t_cub *cub;

	if (!check_args(argc ,argv[1], argv[0]))
		return (1);
	cub = malloc (sizeof(t_cub)); //colocar essas duas linhas em um arquivo de init structs
	if (!cub)
	{
		printf("Error\n Memory allocation error\n");
		return (1);
	}
	if (!init_parse_info(cub, argv[1]))
	{
		// free_array( &cub->parse->file);
		// //colocar o free ff
		// free_parse(cub->parse);
		// free_structs(cub);
		//free(cub);
		ft_exit(cub);
		return (1);
	}
	//readmap guardar em algum lugar
	//fazer a validadação
	//free_parse(cub->parse);
	free_structs(cub);
	free(cub);
	return(0);
	//init_window(argv);

	return 0;
}
