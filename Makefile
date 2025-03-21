NAME = cub3d

SRCS_DIR = ./srcs

LIBFT = ./includes/libft/libft.a
LIBFT_DIR = ./includes/libft

MLIBX = ./includes/minilibx-linux/libmlx.a
MLIBX_DIR = ./includes/minilibx-linux

SRCS = $(SRCS_DIR)/cub.c \
		$(SRCS_DIR)/parse/init_parse_structs.c \
		$(SRCS_DIR)/parse/init_parse_textures_info.c \
		$(SRCS_DIR)/parse/parse_textures.c \
		$(SRCS_DIR)/parse/read_parse_file.c \
		$(SRCS_DIR)/parse/utils_parse.c \
		$(SRCS_DIR)/parse/validate_parse.c \
		$(SRCS_DIR)/parse/validate_map.c 

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L ./includes/minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm -lz

# ---------- COLORS ---------- #
GREEN = \033[1;32m
BROWN = \033[1;33m
P = \033[1;31m


RM = rm -f

$(NAME): $(LIBFT) $(MLIBX) $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)\nCOMPILED$(R)"

all: $(NAME)
#bonus

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	
$(MLIBX):
	@$(MAKE) -C $(MLIBX_DIR) > /dev/null 2>&1

#bonus: $(B_NAME)

#$(B_NAME): $(LIBFT) $(MLIBX) $(B_SRCS)
#	$(CC) $(CFLAGS) $(B_SRCS) $(LIBFT) $(MLXFLAGS) -o $(B_NAME)

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