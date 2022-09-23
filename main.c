#include "cub3d.h"

void	error_exit(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	perror("");
	exit(EXIT_FAILURE);
}

int	main(int ac, char *av[])
{
	if (ac != 2 && ac != 3)
		error_exit("Argument Error\n");
	is_valid(av);

	return (EXIT_SUCCESS);
}
