#include "game_manager.h"



typedef struct rayy
{
	float rayDirX;
	float rayDirY;
	float firstX;
	float firstY;
	float nextX;
	float nextY;
	float dist;
	int mapX;
	int mapY;
	int stepX;
	int stepY;
} raay;

void	wall_casting(t_game_info *info)
{
	int	x;
	raay ray;

	x = -1;
	while (++x < width)
	{
	ray.mapX = (int) info->mapinfo->posX;
	ray.mapY = (int) info->mapinfo->posY;
	// printf("\t%f %f\n", info->mapinfo->posX, info->mapinfo->posY);
	// printf("\t%d %d\n", ray.mapX, ray.mapY);
		ray.rayDirX = info->mapinfo->dirX + info->mapinfo->planeX * ((((float)x * 2) / (float)width) - 1) ;
		ray.rayDirY = info->mapinfo->dirY + info->mapinfo->planeY * ((( (float)x * 2) / (float)width) - 1);
		ray.nextX = fabs(1 / ray.rayDirX);
		ray.nextY = fabs(1 / ray.rayDirY);
		if (ray.rayDirX < 0)
		{
			ray.stepX = -1;
			ray.firstX = (info->mapinfo->posX - ray.mapX) * ray.nextX;
		}
		else
		{
			ray.stepX = 1;
			ray.firstX = (ray.mapX + 1.0 - info->mapinfo->posX) * ray.nextX;
		}
		if (ray.rayDirY < 0)
		{
			ray.stepY = -1;
			ray.firstY = (info->mapinfo->posY - ray.mapY) * ray.nextY;
		}
		else
		{
			ray.stepY = 1;
			ray.firstY = (ray.mapY + 1.0 - info->mapinfo->posY) * ray.nextY;
		}

		int hit = 0;
		int side = 0;
		while (hit == 0)
		{
			// 	printf("x: %d, firstx: %f firstY: %f, nextX: %f, nextY: %f ", x, ray.firstX, ray.firstY, ray.nextX, ray.nextY);
			if (ray.nextX < ray.nextY)
			{
				ray.nextX += ray.firstX;
				ray.mapX += ray.stepX;
				side = 0;
			}
			else
			{
				ray.nextY += ray.firstY;
				ray.mapY += ray.stepY;
				side = 1;
			}
			if (info->mapinfo->map[ray.mapY][ray.mapX] >= '1')
				hit = 1;
			// 	printf(" %d %d %c %d %d\n", ray.mapX, ray.mapY, info->mapinfo->map[ray.mapY][ray.mapX], hit, side);

		}
		printf("x: %d, mapX: %d mapY: %d\n", x, ray.mapX, ray.mapY);
		if (side == 0)
		{
			ray.dist = (ray.mapY - info->mapinfo->posY + (1 - ray.stepY) / 2) / ray.rayDirY;
			printf("mapy: %d posY: %f stepY: %d rayDirY: %f", ray.mapY, info->mapinfo->posY, ray.stepY, ray.rayDirY);
		}
		else
		{
			ray.dist = (ray.mapX - info->mapinfo->posX + (1 - ray.stepX) / 2) / ray.rayDirX;
			printf("mapx: %d posX: %f stepX: %d rayDirX: %f", ray.mapX, info->mapinfo->posX, ray.stepX, ray.rayDirX);
		}

		ray.dist = fabs(ray.dist);
		int lineHeight = (int)(height / ray.dist);
		printf("dist: %f Height: %d\n", ray.dist, lineHeight);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if(drawEnd >= height)
			drawEnd = height - 1;

		printf("x: %d dist: %f drawstart: %d drawend: %d\n", x, ray.dist, drawStart, drawEnd);
		for (int i = drawStart ;i < drawEnd; i++)
		{
			info->buf[i][x] = 65536;
		}
	}
}
