NAME = push_swap

$(NAME):
	clang -g main.c -o $@

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
