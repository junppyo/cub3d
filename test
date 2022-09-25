# include <stdio.h>
#include <fcntl.h>
# include "cub3d.h"
int main()
{
	char *tmp;
	char s[111];
	int fd = open("a.txt", O_RDONLY);
	tmp = get_next_line(fd);
	int i = 0;
	while (tmp)
	{
		// printf("%s\n", tmp);
		if (!tmp[5])
			s[i++] = 'w';
		else
			s[i++] = tmp[5];
		tmp = get_next_line(fd);
	}
	printf("%s\n", s);
}