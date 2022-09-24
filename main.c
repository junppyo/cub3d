/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:43:44 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/24 08:46:18 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "valid_check.h"

int	main(int ac, char *av[])
{
	t_game_info	gameinfo;

	gameinfo.imginfo = malloc(sizeof(t_img_info));
	gameinfo.mapinfo = malloc(sizeof(t_map_info));
	gameinfo.fd = open(av[1], O_RDONLY);
	init_map_info(&gameinfo);
	printf("row: %d\ncol: %d\n", gameinfo.mapinfo->row, gameinfo.mapinfo->col);
	for (int i = 0 ; i < gameinfo.mapinfo->row; i++)
		printf("%s", gameinfo.mapinfo->map[i]);
	if (chk_map(gameinfo.mapinfo))
		printf("error\n");
	if ( chk_x_wall(gameinfo.mapinfo)) 
		printf("error1\n");
	if ( chk_y_wall(gameinfo.mapinfo))
		printf("error2\n");
	if (ac != 2)
		error_exit("Argument Error\n[USAGE]\t./cub3d {$FILE_NAME}.cub\n");
	// valid_check_and_fill_info(av, &gameinfo.imginfo);
	return (EXIT_SUCCESS);
}
