# コンパイラの指定
CC = gcc

# コンパイルオプション
CFLAGS = -Wall -Wextra -Werror

# 実行ファイル名
NAME = fract_ol

# ソースファイル
SRC = main.c julia.c complex.c window.c

# プリント関数のライブラリ（またはオブジェクトファイル）のパス
PRINTF = printf/ft_printf.a

# オブジェクトファイル
OBJ = $(SRC:.c=.o)

all:$(NAME)

%.o: %.c
	$(CC)  -Imlx -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -L/opt/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make -C printf clean
	rm -f $(OBJ)

fclean: clean
	make -C printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
