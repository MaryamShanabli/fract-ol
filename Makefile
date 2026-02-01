NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3
LDFLAGS = -Lminilibx-linux -L/usr/lib
LIBS = -lmlx_Linux -lXext -lX11 -lm -lz

SRC = main.c fractal.c events.c utils.c
OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

all: $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
