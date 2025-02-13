NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
#MINILXFLAGS = -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd -no-pie

RM = rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c
OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	$(MAKE) --no-print-directory -C $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all
