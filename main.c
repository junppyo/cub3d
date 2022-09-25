/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:43:44 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/25 10:25:26 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
static void	leak_check(void)
{
	system("leaks a.out");
}
*/

int	main(int ac, char *av[])
{
	t_game_info	gameinfo;

	//atexit(leak_check);
	if (ac != 2)
		error_exit("Argument Error\n[USAGE]\t./cub3d {$FILE_NAME}.cub\n");
	/*
	printf("row: %d\ncol: %d\n", gameinfo.mapinfo->row, gameinfo.mapinfo->col);
	for (int i = 0 ; i < gameinfo.mapinfo->row; i++)
		printf("%s", gameinfo.mapinfo->map[i]);
	*/
	gameinfo_init(&gameinfo);
	valid_check_and_fill_info(av, &gameinfo);
	return (EXIT_SUCCESS);
}
