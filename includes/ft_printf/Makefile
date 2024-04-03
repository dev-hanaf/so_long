RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

AR = ar rcs 

SRC = ft_printf.c \
		ft_dicimal.c \
		ft_utils.c \
		count_val_flags.c  \
		ft_putchar.c \
		rond_point.c \
		ft_minus.c\
		ft_width.c\
		ft_parser.c\
		ft_get_precision.c ft_precision.c ft_zero.c ft_format.c \
		ft_mandatory_flags.c \
		rond_point_u.c ft_precision_u.c ft_putnbr_u.c \
		rond_point_x.c ft_precision_x.c ft_puthexa.c \
		rond_point_xx.c ft_precision_xx.c ft_putaddresse.c \
		rond_point_s.c ft_precision_s.c ft_putstr.c \
		ft_bonus_utils.c ft_bonus_utils_u.c  ft_bonus_utils_x.c \
		ft_bonus_utils_s.c ft_bonus_utils_xx.c ft_bonus_utils_p.c \
		rond_point_p.c ft_precision_p.c  rond_point_c.c \
		rond_point_precentage.c 
		
OBJ = $(SRC:.c=.o)

all: header $(NAME)

bonus :header  all

$(NAME) : $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OBJ)

header:
	@echo "$(RED)"
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