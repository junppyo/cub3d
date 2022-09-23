#ifndef CUB3D_H
# define CUB3D_H

/* custom.h */
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./valid_check.h"

/* f : perror, strerror, printf */
# include <stdio.h>

/* f : open, close */
# include <fcntl.h>

# define RGB_LEN 3

typedef struct s_map_info
{
	int		*floor;
	int		*celling;
	char	*east;
	char	*west;
	char	*south;
	char	*north;
}t_map_info;

/*
		valid_check.c
*/
void	valid_check_and_fill_info(char *av[], t_map_info *info);
/*
		utils.c
*/
void	free_map_info(t_map_info *info);
void	error_exit(char *message);

#endif
