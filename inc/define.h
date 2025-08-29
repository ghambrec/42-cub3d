#ifndef DEFINE_H
#define DEFINE_H

# include <stdint.h>

// COLORS
# define CMM_WALL ((uint32_t)0x5D403780)
# define CMM_FLOOR ((uint32_t)0x4CAF5080)
# define CMM_PLAYER ((uint32_t)0xE5393580)
# define CMM_DIR ((uint32_t)0xFFD00080)

// nur zum testen
# define BLACK ((uint32_t)0x000000FF)
# define RED ((uint32_t)0xFF0000FF)
# define WHITE ((uint32_t)0xFFFFFFFF)
# define GREY ((uint32_t)0x808080FF)
# define YELLOW ((uint32_t)0xFFFF00FF)
# define WHITE ((uint32_t)0xFFFFFFFF)

// GAME
# define GAME_SCREEN_WIDTH 1920
# define GAME_SCREEN_HEIGTH 1080

// MOVEMENT
# define MV_ANGLE 0.05

// MINIMAP
# define MM_SIZE 4

#endif