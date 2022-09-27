/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:09:38 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 09:33:29 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	leak_check(void)
{
	system("leaks cub3D");
}

void	show_struct(t_game_info *info)
{
	printf("========[show_struct]========\n\n");
	for (int i = 0; i < RGB_LEN; i++)
		printf("celling[%d]:%d\n", i, info->imginfo->celling[i]);
	printf("\n");
	for (int i = 0; i < RGB_LEN; i++)
		printf("floor[%d]:%d\n", i, info->imginfo->floor[i]);
	printf("\n");
	printf("NORTH:%s\n", info->imginfo->north);
	printf("SOUTH:%s\n", info->imginfo->south);
	printf("EAST:%s\n", info->imginfo->east);
	printf("WEST:%s\n", info->imginfo->west);
	printf("\n");
	for (int i = 0; i < info->mapinfo->row; i++)
		printf("%s", info->mapinfo->map[i]);
	printf("\n============================\n\n");
}
