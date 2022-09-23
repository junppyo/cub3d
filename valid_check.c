#include "cub3d.h"

static int	is_invalid_extension(char *filename)
{
	size_t	i;

	i = 0;
	while (filename[i] != '\0')
		i++;
	if (filename[i - 1] == 'b' && filename[i - 2] == 'u' \
		&& filename[i - 3] == 'c' && filename[i - 4] == '.')
		return (0);
	return (1);
}

static void	valid_check(int fd)
{
	int		open_ret;
	char	


}

void	is_valid(char *av[])
{
	int	fd;

	if (is_invalid_extension(av[1]))
		error_exit("Map's Extension Must Be .cub!\n");
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		error_exit("Open Error.\n");
	texture_check(fd);
}
