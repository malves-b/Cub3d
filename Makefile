TARGET = Cub3D

# Diretórios dos arquivos fontes
FILES = $(wildcard srcs/*.c includes/libft/*.c includes/minilibx-linux/*.c)

# Objetos gerados
OBJS = $(patsubst srcs/%.c, objs/srcs/%.o, $(wildcard srcs/*.c)) \
       $(patsubst includes/libft/%.c, objs/includes/libft/%.o, $(wildcard includes/libft/*.c)) \
       $(patsubst includes/minilibx-linux/%.c, objs/includes/minilibx-linux/%.o, $(wildcard includes/minilibx-linux/*.c))

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Diretórios e bibliotecas da minilibx
MLX_DIR = includes/minilibx-linux
MLX_LIBS = -L$(MLX_DIR) -lmlx -lX11 -lm

GREEN = \033[1;32m
BROWN = \033[1;33m
P = \033[1;31m

TOTAL_FILES := $(words $(OBJS))
COMPILED_FILES := 0

# Compilação geral
all: create_objs $(TARGET)

create_objs:
	@mkdir -p objs/srcs objs/includes/libft objs/includes/minilibx-linux

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(MLX_LIBS)
	@echo "$(GREEN)\nCOMPILED$(R)"

define compile_template
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	@printf "$(P)\rCOMPILING: $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%%$(R)"
	@$(CC) $(CFLAGS) -c $< -o $@
endef

# Compilação dos arquivos .o
objs/srcs/%.o: srcs/%.c
	$(compile_template)

objs/includes/libft/%.o: includes/libft/%.c
	$(compile_template)

objs/includes/minilibx-linux/%.o: includes/minilibx-linux/%.c
	$(compile_template)

# Limpeza dos objetos e do executável
clean:
	@$(RM) $(OBJS)
	@echo "$(BROWN)OBJS REMOVED$(R)"

fclean: clean
	@$(RM) $(TARGET)
	@echo "$(BROWN)EXE REMOVED$(R)"

re: fclean all

.PHONY: all clean fclean re
	@$(RM) $(TARGET)
	@echo "$(BROWN)EXE REMOVED$(R)"

re: fclean all

.PHONY: all clean fclean re