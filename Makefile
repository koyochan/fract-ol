CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

NAME = fract_ol

SRC = src/main.c src/julia.c src/complex.c src/window.c src/sub.c

OBJ = $(SRC:.c=.o)

all:$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -L/opt/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
