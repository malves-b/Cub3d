NAME = cub3d

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
	$(PARSE_DIR)/init_parse_structs.c $(PARSE_DIR)/read_parse_file.c \
	$(PARSE_DIR)/utils_parse.c $(PARSE_DIR)/validate_parse.c

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

.PHONY: all clean fclean re