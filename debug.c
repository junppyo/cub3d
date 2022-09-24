/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:09:38 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/23 15:10:41 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	leak_check(void)
{
	system("leaks a.out");
}

int	main(int ac, char *av[])
{
	t_game_info	gameinfo;

	gameinfo.imginfo = malloc(sizeof(t_img_info));
	gameinfo.mapinfo = malloc(sizeof(t_map_info));
	atexit(leak_check);
	if (ac != 2)
		error_exit("Argument Error\n[USAGE]\t./cub3d {$FILE_NAME}.cub\n");
	valid_check_and_fill_info(av, gameinfo.imginfo);
	free_img_info(gameinfo.imginfo);
	return (EXIT_SUCCESS);
}
