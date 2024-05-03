CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fract_ol

MLX = 

SRC = src/main.c src/julia.c src/complex.c src/window.c src/sub.c

OBJ = $(SRC:.c=.o)

all:$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -L/opt/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit -o $(NAME) 
	make -s -C mlx


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -s -C mlx clean

re: fclean all

.PHONY: all clean fclean re
