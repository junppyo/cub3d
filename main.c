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

int	main(int ac, char *av[])
{
	t_map_info	map_info;

	if (ac != 2)
		error_exit("Argument Error\n[USAGE]\t./cub3d {$FILE_NAME}.cub\n");
	valid_check_and_fill_info(av, &map_info);
	return (EXIT_SUCCESS);
}
