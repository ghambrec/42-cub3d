#ifndef FUNCTIONS_H
#define FUNCTIONS_H

# include "../lib/myLibft/include/my_libft.h"
# include "structs.h"

// PARSING
void	game_init(t_game *game);
void	arg_validation(char **argv, int n);
void	map_validation(t_game *game);
void	char_validation(char *map);
void	map_open(t_map_info *map_info);
int		floodfill_validation(t_game *game);
void	create_map(t_game *game);
void	get_player_pos(t_game *game);

// EXIT
void	exit_success(t_game *game);
void	exit_failure(t_game *game, char *msg);
void	clean_game(t_game *game);

#endif