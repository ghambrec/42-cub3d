#ifndef DEFINE_H
#define DEFINE_H

# include <stdint.h>

// MINIMAP
# define CMM_WALL ((uint32_t)0x5D403780)
# define CMM_FLOOR ((uint32_t)0x4CAF5080)
# define CMM_PLAYER ((uint32_t)0xE5393580)
# define CMM_DIR ((uint32_t)0xFFD00080) // nicht benoetigt?
# define CMM_RAYS ((uint32_t)0xEAF52580)
# define MM_SIZE 4
# define MM_PLAYER_SIZE 4

// nur zum testen
# define BLACK ((uint32_t)0x000000FF)
# define RED ((uint32_t)0xFF0000FF)
# define WHITE ((uint32_t)0xFFFFFFFF)
# define GREY ((uint32_t)0x808080FF)
# define YELLOW ((uint32_t)0xFFFF00FF)
# define WHITE ((uint32_t)0xFFFFFFFF)
# define CEIL  ((uint32_t)0x87CEEBFF)
# define FLOOR ((uint32_t)0x3A5F0BFF)

// GAME
# define GAME_SCREEN_WIDTH 1920
# define GAME_SCREEN_HEIGTH 1080
# define GAME_FOV 0.66

// MOVEMENT
// # define MV_ANGLE 0.075
// # define MV_SPEED 0.05
# define MV_ANGLE 0.04
# define MV_SPEED 0.03


#endif