RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FT_PRINTF_DIR = ./includes/ft_printf
LIBFT_DIR = ./includes/LIBFT
GET_NEXT_LINE = ./includes/get_next_line/get_next_line.c

SRC = so_long.c $(GET_NEXT_LINE) ./includes/get_next_line/get_next_line_utils.c moves.c parsing.c utils.c flood_fill.c draw.c
MLX = -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

NAME = so_long

all: header $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(MLX) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

header:
	@echo "$(GREEN)"
	@echo " ██░ ██  ▄▄▄       ███▄    █  ▄▄▄        █████▒"
	@echo "▓██░ ██▒▒████▄     ██ ▀█   █ ▒████▄    ▓██   ▒ "
	@echo "▒██▀▀██░▒██  ▀█▄  ▓██  ▀█ ██▒▒██  ▀█▄  ▒████ ░ "
	@echo "░▓█ ░██ ░██▄▄▄▄██ ▓██▒  ▐▌██▒░██▄▄▄▄██ ░▓█▒  ░ "
	@echo "░▓█▒░██▓ ▓█   ▓██▒▒██░   ▓██░ ▓█   ▓██▒░▒█░    "
	@echo " ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒░   ▒ ▒  ▒▒   ▓▒█░ ▒ ░    "
	@echo " ▒ ░▒░ ░  ▒   ▒▒ ░░ ░░   ░ ▒░  ▒   ▒▒ ░ ░      "
	@echo " ░  ░░ ░  ░   ▒      ░   ░ ░   ░   ▒    ░ ░    "
	@echo " ░  ░  ░      ░  ░         ░       ░  ░        "
    
	@echo "$(NC)"  
	
	@printf "$(YELLOW)ahanaf Sama!$(NC)\n"

# .SECONDARY : $(OBJ)