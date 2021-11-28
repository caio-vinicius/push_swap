NAME = push_swap

LIBRARY = libft/libft.a

test: $(LIBRARY)
	gcc -g -I include/ -I libft/ parsing.c operations/*.c list/*.c main.c $(LIBRARY) -o push_swap

$(NAME): $(LIBRARY)
	gcc -g -I include/ -I libft/ main.c $(LIBRARY) -o $@

$(LIBRARY):
	$(MAKE) -C libft

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
