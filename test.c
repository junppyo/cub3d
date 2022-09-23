#include "cub3d.h"

/*
    test.txt
    1111111
    \n
*/

int	main(int ac, char *av[])
{
    char *line;
    int     fd;

    fd = open(av[1], 0);
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
	return (EXIT_SUCCESS);
}
