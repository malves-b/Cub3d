NAME = cub3D

SRCS_DIR = ./srcs
PARSE_DIR = ./srcs/parse

LIBFT = ./includes/libft/libft.a
LIBFT_DIR = ./includes/libft

MLIBX = ./includes/minilibx-linux/libmlx.a
MLIBX_DIR = ./includes/minilibx-linux

SRCS = $(SRCS_DIR)/main.c \
	$(SRCS_DIR)/set_direction_vector.c $(SRCS_DIR)/free.c \
	$(SRCS_DIR)/init_mlx.c $(SRCS_DIR)/set_player_position.c \
	$(SRCS_DIR)/utils.c $(SRCS_DIR)/init_raycasting.c \
	$(SRCS_DIR)/run_cub.c $(SRCS_DIR)/raycasting.c \
	$(SRCS_DIR)/raycasting_utils.c $(SRCS_DIR)/textures_settings.c \
	$(SRCS_DIR)/textures_utils.c \
	$(PARSE_DIR)/validate_args.c \
	$(PARSE_DIR)/init_structs.c \
	$(PARSE_DIR)/init_parse_file.c \
	$(PARSE_DIR)/color_textures_parse.c \
	$(PARSE_DIR)/parse_map_textures.c \
	$(PARSE_DIR)/rgb_to_hexa.c \
	$(PARSE_DIR)/validate_map.c \
	$(PARSE_DIR)/flood_f.c \
	$(PARSE_DIR)/populate_structs.c \
	$(PARSE_DIR)/utils_map.c \
	$(PARSE_DIR)/free_parse.c \
	$(PARSE_DIR)/validate_texture.c \
	$(PARSE_DIR)/utils_textures_color.c 

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L ./includes/minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm -lz

# ---------- COLORS ---------- #
GREEN = \033[1;32m
BROWN = \033[1;33m
P = \033[1;31m

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(MLIBX) $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)\nCOMPILED$(R)"

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	
$(MLIBX):
	@echo "Compiling minilibx..."
	@$(MAKE) -C $(MLIBX_DIR) > /dev/null 2>&1

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(MLIBX_DIR) > /dev/null 2>&1
	@echo "$(BROWN)OBJS REMOVED$(R)"

fclean: clean
	@$(RM) $(NAME) $(LIBFT) $(MLIBX) > /dev/null 2>&1
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(BROWN)EXE REMOVED$(R)"

re: fclean all
