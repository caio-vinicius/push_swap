NAME = push_swap

LIBRARY = libft/libft.a

$(NAME): $(LIBRARY)
	gcc -g -I include/ -I libft/ main.c $(LIBRARY) -o $@

$(LIBRARY):
	$(MAKE) -C libft

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
