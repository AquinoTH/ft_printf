NAME = libftprintf.a

FILES = ft_printf_utils.c ft_printf.c ft_parsing.c

FILES_OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	ar rcs $(NAME) $(FILES_OBJ)

%.o: %.c
	cc -c $< -o $@ -Wall -Wextra -Werror

clean:
	rm -f $(FILES_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
