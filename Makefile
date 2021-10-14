SRCDIR = ./src
LIBDIR = ./libft
HEADER = ft_printf.h

SRC = flag_proc.c ft_printf.c init.c print_decimal.c print_format.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIB = libft.a

%.o: %.c %(LIB) $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ -L$(LIBDIR) -lft

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIB):
	make -C $(LIBDIR)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
