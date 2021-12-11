NAME = push_swap

LIBRARY = libft/libft.a

test: $(LIBRARY)
	gcc -Wall -Wextra -g3 -fsanitize=address -g -I include/ -I libft/ parsing.c sort/*.c operations/*.c list/*.c push_swap.c $(LIBRARY) -o push_swap

$(NAME): $(LIBRARY)
	gcc -g -I include/ -I libft/ push_swap.c $(LIBRARY) -o $@

$(LIBRARY):
	$(MAKE) -C libft
	$(MAKE) bonus -C libft

clean:
	rm -rf $(NAME)
	$(MAKE) clean -C libft

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C libft

#re: fclean $(NAME)
re: fclean test
