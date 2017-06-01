# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/24 15:08:19 by ybelilov          #+#    #+#              #
#    Updated: 2017/03/24 15:08:20 by ybelilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = main.c \
		input_data.c \
			put_pat.c \
				map_analysis.c

LIB = libft/libftprintf.a

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/ re
	@clang $(FLAGS) $(LIB) $(OBJ) -o $(NAME)
	@echo "Compilation done!"

%.o: %.c
	@clang -c $(FLAGS) -o $@ $<

clean:
	@rm -f $(OBJ)
	@make -C ./libft/ clean
	@echo "Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft/ fclean
	@echo "Executable removed!"

re: fclean all
