/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:54:11 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 20:05:43 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_manager.h"

static void	init_ray(t_game_info *info, t_ray *r, int y)
{
	r->posZ = 0.5 * height;
	r->p = y - height / 2;
	r->rowDistance = r->posZ / r->p;
	r->rayDirX0 = info->mapinfo->dirX - info->mapinfo->planeX;
	r->rayDirY0 = info->mapinfo->dirY - info->mapinfo->planeY;
	r->rayDirY1 = info->mapinfo->dirY + info->mapinfo->planeY;
	r->rayDirY1 = info->mapinfo->dirY + info->mapinfo->planeY;
	r->floorStepX = r->rowDistance * (r->rayDirX1 - r->rayDirX0) / width;
	r->floorStepY = r->rowDistance * (r->rayDirY1 - r->rayDirY0) / width;
	r->floorX = info->mapinfo->posX + r->rowDistance * r->rayDirX0;
	r->floorY = info->mapinfo->posY + r->rowDistance * r->rayDirY0;
}

static void set_buffer(t_game_info *info, t_ray *r, int x, int y)
{
	const int	floorTexture = 1;
	const int	cellingTexture = 1;

	r->cellX = (int)r->floorX;
	r->cellY = (int)r->floorY;
	r->tx = (int)(texWidth * (r->floorX - r->cellX)) & (texWidth - 1);
	r->ty = (int)(texHeight * (r->floorX - r->cellY)) & (texHeight - 1);
	r->floorX += r->floorStepX;
	r->floorY += r->floorStepY;
	r->color = info->texture[floorTexture][texWidth * r->ty + r->tx];
	r->color = (r->color >> 1) & 8355711;
	r->buf[y][x] = r->color;
	r->color = info->texture[cellingTexture][texWidth * r->ty + r->tx];
	r->color = (r->color >> 1) & 8355711;
	r->buf[y][x] = r->color;
}

void	floor_casting(t_game_info *info, t_ray *ray)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		init_ray(info, ray, y);
		x = -1;
		while (++x < width)
		{
			set_buffer(info, ray, x, y);
		}
	}
}
