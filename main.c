/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:43:44 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 19:54:06 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_game_info	gameinfo;
	t_img_info	img_info;
	t_map_info	map_info;
	setbuf(stdout, NULL);
	if (ac != 2)
		error_exit("Argument Error\n[USAGE]\t./cub3d {$FILE_NAME}.cub\n");
	gameinfo_init(&gameinfo, &img_info, &map_info);
	valid_check_and_fill_info(av, &gameinfo);

	game_start(&gameinfo);
	return (EXIT_SUCCESS);
}
