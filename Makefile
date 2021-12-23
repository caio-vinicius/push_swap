# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 16:44:53 by csouza-f          #+#    #+#              #
#    Updated: 2021/12/23 16:46:30 by csouza-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBRARY = src/libft/libft.a

all: $(NAME)

$(NAME): $(LIBRARY)
	gcc -Wall -Wextra -Werror -fsanitize=address -I src/include/ \
	-I src/libft/ src/parsing/*.c src/sort/*.c src/operations/*.c \
        src/list/*.c src/numbers/*.c src/utils/* src/push_swap.c \
	$(LIBRARY) -o $@

$(LIBRARY):
	git submodule update --init --recursive
	$(MAKE) -C src/libft
	$(MAKE) bonus -C src/libft

clean:
	rm -rf $(NAME)
	$(MAKE) clean -C src/libft

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C src/libft

re: fclean $(NAME)
