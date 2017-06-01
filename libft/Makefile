NAME = libftprintf.a

SRC =	ft_print_to.c \
		ft_printf.c \
		ft_take_form.c \
		ft_working_with_form.c \
		ft_itoabase.c \
		ft_print.c \
		ifs.c \
		ifs2.c \
		w_char.c \
		w_char2.c

OBJ = $(SRC:.c=.o)

HEAD = -I ft_printf.h

CFLAGS = -c -Wall -Wextra -Werror

LIBINC = -I libft/libft.h -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ re
	cp libft/libft.a $(NAME)
	ar -q  $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(HEAD) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all