SRC_DIR = ./src
LIB_DIR = ./libft
SRC = flag_proc.c ft_printf.c init.c print_decimal.c print_format.c \
	  ft_atoi.c ft_strchr.c ft_putnbr_fd.c ft_putchar_fd.c ft_substr.c\
	  ft_strlen.c ft_isdigit.c ft_strlcpy.c print_char.c print_str.c \
	  ft_putstr_fd.c print_hex.c print_pointer.c print_unsigned.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = ./src/ft_printf.h

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean fclean re
