#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

# include "cub3d.h"

# define X_EVENT_KEY_EXIT			17
# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

/*
		game_manager
*/
int		game_exit(t_game_info *info);
void	game_start(t_game_info *g);
/*
		game_key
*/
int		press_key(int key_code, t_game_info *game);

#endif
