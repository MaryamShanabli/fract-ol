NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Imlx
LDFLAGS = -Lmlx
LIBS = -lmlx -framework OpenGL -framework AppKit

SRC = main.c fractal.c utils.c events.c
OBJ = $(SRC:.c=.o)

MLX_LIB = mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

