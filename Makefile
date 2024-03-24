CC = cc 
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FT_PRINTF_DIR = ./includes/ft_printf
LIBFT_DIR = ./includes/LIBFT
GET_NEXT_LINE= ./includes/get_next_line/get_next_line.c 

SRC = so_long.c ft_split_so_long.c  ./includes/get_next_line/get_next_line.c  ./includes/get_next_line/get_next_line_utils.c moves.c

MLX =  -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC.c:o)

all:
#	make re -C $(FT_PRINTF_DIR)
	make -C $(LIBFT_DIR)

	$(CC) $(SRC) $(MLX) -L./includes/LIBFT -lft -o so_long

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f so_long

re:fclean all
	