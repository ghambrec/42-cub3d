#include "cub3d.h"

static void	set_values_dummy(t_game *game)
{
	game->texture_path.north = ft_strdup("./textures/bus.png");
	game->texture_path.east = ft_strdup("./textures/bus.png");
	game->texture_path.south = ft_strdup("./textures/bus.png");
	game->texture_path.west = ft_strdup("./textures/bus.png");
}

static void	load_textures(t_game *game)
{
	set_values_dummy(game); //nur zum testen, da das noch nicht ueber die map validierung laeuft

	game->textures[T_NORTH] = mlx_load_png(game->texture_path.north);
	if (!game->textures[T_NORTH])
	{
		exit_failure(game, "failed to load png (mlx_load_png)");
	}
	game->textures[T_EAST] = mlx_load_png(game->texture_path.east);
	if (!game->textures[T_EAST])
	{
		exit_failure(game, "failed to load png (mlx_load_png)");
	}
	game->textures[T_SOUTH] = mlx_load_png(game->texture_path.south);
	if (!game->textures[T_SOUTH])
	{
		exit_failure(game, "failed to load png (mlx_load_png)");
	}
	game->textures[T_WEST] = mlx_load_png(game->texture_path.west);
	if (!game->textures[T_WEST])
	{
		exit_failure(game, "failed to load png (mlx_load_png)");
	}
}

void	init_mlx(t_game *game)
{
	// mlx init
	game->mlx = mlx_init(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGTH, "cub3d", false);
	if (!game->mlx)
		exit_failure(game, "failed to init the mlx (mlx_init)");

	load_textures(game);
	free(game->texture_path.north);
	free(game->texture_path.east);
	free(game->texture_path.south);
	free(game->texture_path.west);
}
