# ---------- COLORS ---------- #
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m

# ---------- MAIN ---------- #
NAME := cub3D
CC := cc
INCLUDE_DIR := ./inc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR) -g -O3 -MMD
# MMD -> Automatische Rebuilds bei Header-Änderung (.d Dateien im obj folder)
# O3 -> Maximale Compiler-Optimierung

# Prefer pkg-config for glfw (fallback to Homebrew). Add GLFW cflags to CFLAGS when available.
PKG_CONFIG := $(shell command -v pkg-config 2>/dev/null)
GLFW_PKG_CFLAGS := $(shell pkg-config --cflags glfw3 2>/dev/null)
GLFW_PKG_LIBS := $(shell pkg-config --libs glfw3 2>/dev/null)
HOMEBREW_PREFIX := $(shell brew --prefix 2>/dev/null || echo /opt/homebrew)
GLFW_FALLBACK_LIBS := -L$(HOMEBREW_PREFIX)/lib -lglfw
GLFW_LIBS := $(if $(GLFW_PKG_LIBS),$(GLFW_PKG_LIBS),$(GLFW_FALLBACK_LIBS))
ifneq ($(GLFW_PKG_CFLAGS),)
CFLAGS += $(GLFW_PKG_CFLAGS)
endif

# ---------- LIB ---------- #
LIB_DIR = ./lib
LIBFT_DIR = $(LIB_DIR)/myLibft
LIBFT_NAME = libft.a
LIBFT_FULL = $(LIBFT_DIR)/$(LIBFT_NAME)
MLX_DIR = $(LIB_DIR)/mlx
MLX_NAME = $(MLX_DIR)/build/libmlx42.a
# macOS: remove -ldl and resolve glfw via pkg-config or Homebrew
MLX_FULL = $(MLX_NAME) $(GLFW_LIBS) -pthread -lm

# ---------- SOURCES ---------- #
SOURCE_DIRS = 	src \
				src/parsing \
				src/exit \
				src/minimap \
				src/hooks \
				src/movement \
				src/helper \
				src/init \
				src/raycasting

VPATH = $(SOURCE_DIRS)

SOURCES = main.c

# HELPERS
SOURCES +=	helpers.c 

# INIT
SOURCES +=	init_game.c \
			init_mlx.c \
			init_hooks.c

# PARSING
SOURCES += 	check_args.c \
			map_char_validation.c \
			map_validation.c \
			map_open.c \
			floodfill.c \
			player_position.c \
			texture_check.c \
			check_dublicates.c

# EXIT
SOURCES +=	exit.c \
			clean_game.c

# HOOKS
SOURCES +=	key_hook.c \
			resize_hook.c \
			loop_hook.c

# MINIMAP
SOURCES +=	create_minimap.c \
			helper.c \
			paint_background.c \
			paint_minimap.c \
			paint_player.c

# MOVEMENT
SOURCES +=	turns.c \
			walk.c

# RAYCASTING
SOURCES +=	raycasting.c \
			raycasting_calc.c \
			raycasting_calc_textures.c \
			draw_minimap_rays.c \
			draw_rays.c

# ---------- OBJECTS ---------- #
OBJECT_DIR = obj
OBJECTS = $(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))

# ---------- RULES ---------- #
all: $(NAME)

$(NAME): checkMyLibft $(LIBFT_NAME) checkMLX createLibMLX $(OBJECTS)
	@echo "$(YELLOW)Compiling $(NAME)...$(NC)"
	@cc $(CFLAGS) $(OBJECTS) $(LIBFT_FULL) $(MLX_FULL) -lreadline -o $(NAME)
	@if [ -f $(NAME) ]; then \
		echo "$(CYAN)--------------------------------------$(NC)"; \
		echo "$(GREEN)BUILD PROCESS COMPLETED SUCCESSFULLY!$(NC)"; \
		echo "$(CYAN)--------------------------------------$(NC)"; \
	else \
		echo "$(RED)failed to compile $(NAME)$(NC)"; \
		exit 1; \
	fi

checkMyLibft:
	@if [ -d $(LIBFT_DIR) ]; then \
		echo "$(GREEN)myLibft already exists$(NC)"; \
	else \
		echo "$(YELLOW)Downloading myLibft...$(NC)"; \
		mkdir -p $(LIB_DIR); \
		curl -L -o $(LIBFT_DIR).zip https://github.com/ghambrec/42-myLibft/archive/refs/heads/master.zip > /dev/null 2>&1; \
		unzip -o $(LIBFT_DIR).zip > /dev/null 2>&1; \
		mv 42-myLibft-master $(LIBFT_DIR); \
		rm $(LIBFT_DIR).zip; \
		if [ -d $(LIBFT_DIR) ]; then \
			echo "$(GREEN)myLibft downloaded$(NC)"; \
		else \
			echo "$(RED)Error downloading myLibft$(NC)"; \
			exit 1; \
		fi \
	fi	

$(LIBFT_NAME):
	@if [ ! -d $(LIBFT_DIR) ]; then \
		echo "$(RED)myLibft folder doesn't exist! Run 'make checkMyLibft' first to download myLibft$(NC)"; \
	else \
		echo "$(YELLOW)Creating $(LIBFT_NAME)...$(NC)"; \
		make -C $(LIBFT_DIR) > $(LIBFT_DIR)/make_log.txt; \
		if [ -f $(LIBFT_DIR)/$(LIBFT_NAME) ]; then \
			echo "$(GREEN)$(LIBFT_NAME) successfully created$(NC)"; \
		else \
			echo "$(RED)failed to compile $(LIBFT_DIR)$(NC)"; \
			exit 1; \
		fi \
	fi

checkMLX:
	@if [ -d $(MLX_DIR) ]; then \
		echo "$(GREEN)MLX42 already exists$(NC)"; \
	else \
		echo "$(YELLOW)Downloading MLX42...$(NC)"; \
		mkdir -p $(LIB_DIR); \
		curl -L -o $(MLX_DIR).zip https://github.com/codam-coding-college/MLX42/archive/refs/heads/master.zip > /dev/null 2>&1; \
		unzip -o $(MLX_DIR).zip > /dev/null 2>&1; \
		mv MLX42-master $(MLX_DIR); \
		rm $(MLX_DIR).zip; \
		if [ -d $(LIBFT_DIR) ]; then \
			echo "$(GREEN)MLX downloaded$(NC)"; \
		else \
			echo "$(RED)Error downloading MLX$(NC)"; \
			exit 1; \
		fi \
	fi

createLibMLX:
	@echo "$(YELLOW)Creating MLX42-LIB...$(NC)"
	@mkdir -p $(MLX_DIR)/make_log
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build > $(MLX_DIR)/make_log/cmake_log.txt
	@make -C $(MLX_DIR)/build -j4 > $(MLX_DIR)/make_log/make_log.txt
	@if [ -f $(MLX_NAME) ]; then \
		echo "$(GREEN)MLX42-LIB successfully created$(NC)"; \
	else \
		echo "$(RED)Error creating MLX42-LIB$(NC)"; \
		exit 1; \
	fi

$(OBJECT_DIR)/%.o: %.c | $(OBJECT_DIR)
	@printf "$(YELLOW)Compiling $(CYAN)$<\n$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR):
	@echo "$(YELLOW)Creating $(OBJECT_DIR) directory$(NC)"
	@mkdir -p $(OBJECT_DIR)

clean:
	@echo "$(RED)Cleaning object files$(NC)"
	@rm -rf $(OBJECT_DIR)

fclean: clean
	@echo "$(RED)Removing $(NAME)$(NC)"
	@rm -f $(NAME)
	@if [ -d $(LIBFT_DIR)/objects ]; then \
		make fclean -C $(LIBFT_DIR); \
	fi

re: fclean all

# test rule	- compile without flags
test: CFLAGS = -I $(INCLUDE_DIR)
test: all

# del rule	- remove lib folder
del: fclean
	@echo "$(RED)Removing library folder$(NC)"
	@rm -rf $(LIB_DIR)

# run rule - run the game
run: $(NAME)
	@./cub3D map_easy.cub

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=no ./$(NAME) maps/default.cub

.PHONY: all clean fclean re test del run valgrind
