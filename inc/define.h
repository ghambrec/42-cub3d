#ifndef DEFINE_H
#define DEFINE_H

# include <stdint.h>

// MINIMAP
# define CMM_WALL ((uint32_t)0x5D403780)
# define CMM_FLOOR ((uint32_t)0x4CAF5080)
# define CMM_PLAYER ((uint32_t)0xE5393580)
# define CMM_RAYS ((uint32_t)0xEAF52580)
# define MM_SIZE 4
# define MM_PLAYER_SIZE 2

// GAME
# define GAME_SCREEN_WIDTH 1920
# define GAME_SCREEN_HEIGTH 1080
# define GAME_FOV 65

// MOVEMENT
# define MV_ANGLE 0.04
# define MV_SPEED 0.03
# define MV_MOUSE_SENS 0.0005

#endif