#ifndef VALID_CHECK_H
# define VALID_CHECK_H

# include "./cub3d.h"

/*
		valid_check_utils
*/
void	skip_newline(char **line, int fd);
int		*line_to_arr(char *line);
int		get_identifier(char *line);

enum	e_identifier
{
	EAST = 1,
	WEST,
	SOUTH,
	NORTH,
	CELLING,
	FLOOR
};

#endif
