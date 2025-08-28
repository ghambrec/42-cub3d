#ifndef FUNCTIONS_H
#define FUNCTIONS_H

# include "../lib/myLibft/include/my_libft.h"
# include "structs.h"

// PARSING
void	arg_validation(char **argv, int n);
void	map_validation(t_map_info *map_info);
void	char_validation(char *map);
void	map_open(t_map_info *map_info);

// EXIT
void	exit_success(t_game *game);
void	exit_failure(t_game *game, char *msg);
void	clean_game(t_game *game);

// HOOKS
void	key_hook(mlx_key_data_t keydata, void *param);
void	resize_hook(int32_t width, int32_t height, void *param);

// MINIMAP
void	create_minimap(t_game *game);

#endif