NAME = cub3d

SRCS_DIR = ./srcs

LIBFT = ./includes/libft/libft.a
LIBFT_DIR = ./includes/libft

MLIBX = ./includes/minilibx-linux/libmlx.a
MLIBX_DIR = ./includes/minilibx-linux

SRCS = $(SRCS_DIR)/cub.c \
	$(SRCS_DIR)/page1.c

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