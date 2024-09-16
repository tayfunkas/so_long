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
	sources/get_next_line_utils.c 

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = -I./mlx -I../Libft -I../printf

LIBFT_DIR = /home/tkasapog/Desktop/Curriculum/Libft
PRINTF_DIR = /home/tkasapog/Desktop/Curriculum/ft_printf
MLX_DIR = ./mlx

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX_LIB = $(MLX_DIR)/libmlx.a

MLX = -L$(MLX_DIR) -lmlx -lXext -lX11  # For Linux
# MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit  # For macOS

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
