#include "game_manager.h"

static void	init_ray(t_game_info *info, t_ray *ray)
{
	int	i;
	int	j;

	ray->mapX = (int) info->mapinfo->posX;
	ray->mapY = (int) info->mapinfo->posY;
	ray->hit = 0;
	ray->side = 0;
	i = -1;
	if (ray->rebuf)
	{
		while (++i < height)
		{
			j = -1;
			while (++j < width)
				info->buf[i][j] = 0;
		}
	}
	ray->rebuf = 0;
}

static void	init_ray2(t_map_info *info, t_ray *ray, int x)
{
	ray->DirX = info->dirX + info->planeX * \
				(((float)x * 2 / (float)width) - 1);
	ray->DirY = info->dirY + info->planeY * \
				(((float)x * 2 / (float)width) - 1);
	ray->nextX = fabs(1 / ray->DirX);
	ray->nextY = fabs(1 / ray->DirY);
	if (ray->DirX < 0)
		ray->firstX = (info->posX - ray->mapX) * ray->nextX;
	else
		ray->firstX = (ray->mapX + 1.0 - info->posX) * ray->nextX;
	if (ray->DirX < 0)
		ray->stepX = -1;
	else
		ray->stepX = 1;
	if (ray->DirY < 0)
		ray->firstY = (info->posY - ray->mapY) * ray->nextY;
	else
		ray->firstY = (ray->mapY + 1.0 - info->posY) * ray->nextY;
	if (ray->DirY < 0)
		ray->stepY = -1;
	else
		ray->stepY = 1;
}

static void	collision_check(t_map_info *info, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->nextX < ray->nextY)
		{
			ray->nextX += ray->firstX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->nextY += ray->firstY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (info->map[ray->mapY][ray->mapX] >= '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->dist = (ray->mapY - info->posY + (1 - ray->stepY) / 2) / ray->DirY;
	else
		ray->dist = (ray->mapX - info->posX + (1 - ray->stepX) / 2) / ray->DirX;
	ray->dist = fabs(ray->dist);
}

static void	make_buf(t_game_info *info, t_ray *ray, int x)
{
	int	i;

	i = -1;
	while (++i < ray->drawStart - 1)
		info->buf[i][x] = 1234; // floor
	while (++i < ray->drawEnd - 1)
		info->buf[i][x] = 65536; // wall
	while (++i < height - 1)
		info->buf[i][x] = 0; //ceil
	ray->rebuf = 1;
}

void	wall_casting(t_game_info *info)
{
	int		x;
	t_ray	ray;

	x = -1;
	while (++x < width)
	{
		init_ray(info, &ray);
		init_ray2(info->mapinfo, &ray, x);
		collision_check(info->mapinfo, &ray);
		ray.lineHeight = (int)(height / ray.dist);
		ray.drawStart = -ray.lineHeight / 2 + height / 2;
		if (ray.drawStart < 0)
			ray.drawStart = 0;
		ray.drawEnd = ray.lineHeight / 2 + height / 2;
		if (ray.drawEnd >= height)
			ray.drawEnd = height - 1;
		printf("x: %d dist: %f drawstart: %d drawend: %d\n", x, ray.dist, ray.drawStart, ray.drawEnd);
		make_buf(info, &ray, x);
	}
}
