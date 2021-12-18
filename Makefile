NAME = push_swap

LIBRARY = src/libft/libft.a

$(NAME): $(LIBRARY)
	gcc -Wall -Wextra -g -I src/include/ -I src/libft/ src/parsing/*.c src/sort/*.c src/operations/*.c src/list/*.c src/numbers/*.c src/utils/* src/push_swap.c $(LIBRARY) -o $@

$(LIBRARY):
	$(MAKE) -C src/libft
	$(MAKE) bonus -C src/libft

clean:
	rm -rf $(NAME)
	$(MAKE) clean -C src/libft

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C src/libft

re: fclean $(NAME)
