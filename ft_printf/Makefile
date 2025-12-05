NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs

SRC = ft_printf.c \
      utils/ft_putchar.c \
      utils/ft_putstr.c \
      utils/ft_putnbr.c \
      utils/ft_putunbr.c \
      utils/ft_puthex.c \
      utils/ft_putptr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) main test

re:	fclean all

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o main

run: test
	./main

