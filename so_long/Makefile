NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

SOURCES = sources/checks.c \
	sources/fill_map.c \
	sources/free.c \
	sources/map.c \
	sources/render.c \
	sources/move.c \
	sources/so_long.c \
	sources/get_next_line.c \
	sources/get_next_line_utils.c \
	sources/helpers.c
	
OBJECTS = $(SOURCES:.c=.o)

INCLUDES = -I./mlx

MLX_DIR = ./mlx

MLX = -L./mlx -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX) -o $(NAME)
	
$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	$(RM) $(OBJECTS)
	make -C $(MLX_DIR) clean
	
fclean: clean
	$(RM) $(NAME)
	make -C $(MLX_DIR) clean
	
	
re: fclean all

.PHONY: all clean fclean re
