# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 10:17:22 by csouza-f          #+#    #+#              #
#    Updated: 2022/02/27 13:02:36 by csouza-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBRARY = src/libft/libft.a

SOURCES_MAIN = ./src
SOURCES_FILES_MAIN = push_swap.c

SOURCES_LIST = ./src/list
SOURCES_FILES_LIST = ps_llstnew.c ps_lstadd_back.c ps_lstadd_front.c \
                    ps_lstadjustindex.c ps_lstfree.c ps_lsthighest.c \
                    ps_lstlast.c ps_lstlonger.c ps_lstlowest.c ps_lstnew.c \
                    ps_lstrsize.c ps_lstset.c ps_lstsize.c

SOURCES_NUMBERS = ./src/numbers
SOURCES_FILES_NUMBERS = ps_nbrsadd_back.c  ps_nbrsfree.c  ps_nbrsnew.c

SOURCES_OPERATIONS = ./src/operations
SOURCES_FILES_OPERATIONS = push.c push_utils.c rotate_down.c \
                        rotate_down_utils.c rotate_down_utils_utils.c \
                        rotate_up.c rotate_up_utils.c rotate_up_utils_utils.c \
                        swap.c

SOURCES_PARSING = ./src/parsing
SOURCES_FILES_PARSING = parsing.c

SOURCES_SORT = ./src/sort
SOURCES_FILES_SORT = sort_big.c  sort_big_utils.c  sort.c  sort_general.c

SOURCES_UTILS = ./src/utils
SOURCES_FILES_UTILS = stack_is_sorted_ascending.c

SOURCES = $(SOURCES_MAIN) $(SOURCES_LIST) $(SOURCES_NUMBERS) $(SOURCES_OPERATIONS) \
        $(SOURCES_PARSING) $(SOURCES_SORT) $(SOURCES_UTILS)

SOURCES_FILES_MAIN_FULL = $(addprefix $(SOURCES_MAIN)/,$(SOURCES_FILES_MAIN))
SOURCES_FILES_LIST_FULL = $(addprefix $(SOURCES_LIST)/,$(SOURCES_FILES_LIST))
SOURCES_FILES_NUMBERS_FULL = $(addprefix $(SOURCES_NUMBERS)/,$(SOURCES_FILES_NUMBERS))
SOURCES_FILES_OPERATIONS_FULL = $(addprefix $(SOURCES_OPERATIONS)/,$(SOURCES_FILES_OPERATIONS))
SOURCES_FILES_PARSING_FULL = $(addprefix $(SOURCES_PARSING)/,$(SOURCES_FILES_PARSING))
SOURCES_FILES_SORT_FULL = $(addprefix $(SOURCES_SORT)/,$(SOURCES_FILES_SORT))
SOURCES_FILES_UTILS_FULL = $(addprefix $(SOURCES_UTILS)/,$(SOURCES_FILES_UTILS))

OBJECTS = ./objects
OBJECTS_FILES_MAIN = $(patsubst $(SOURCES_MAIN)/%.c,$(OBJECTS)/%.o,$(SOURCES_FILES_MAIN_FULL))
OBJECTS_FILES_LIST = $(patsubst $(SOURCES_LIST)/%.c,$(OBJECTS)/%.o,$(SOURCES_FILES_LIST_FULL))
OBJECTS_FILES_NUMBERS = $(patsubst $(SOURCES_NUMBERS)/%.c,$(OBJECTS)/%.o,$(SOURCES_FILES_NUMBERS_FULL))
OBJECTS_FILES_OPERATIONS = $(patsubst $(SOURCES_OPERATIONS)/%.c,$(OBJECTS)/%.o,$(SOURCES_FILES_OPERATIONS_FULL))
OBJECTS_FILES_PARSING = $(patsubst $(SOURCES_PARSING)/%.c,$(OBJECTS)/%.o,$(SOURCES_FILES_PARSING_FULL))
OBJECTS_FILES_SORT = $(patsubst $(SOURCES_SORT)/%.c,$(OBJECTS)/%.o,$(SOURCES_FILES_SORT_FULL))
OBJECTS_FILES_UTILS = $(patsubst $(SOURCES_UTILS)/%.c,$(OBJECTS)/%.o,$(SOURCES_FILES_UTILS_FULL))
OBJECTS_FILES = $(OBJECTS_FILES_MAIN) $(OBJECTS_FILES_LIST) \
				$(OBJECTS_FILES_NUMBERS) $(OBJECTS_FILES_OPERATIONS) \
				$(OBJECTS_FILES_PARSING) $(OBJECTS_FILES_SORT) \
				$(OBJECTS_FILES_UTILS)

INCLUDE = ./src/include
INCLUDE_LIBFT = ./src/libft

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS_FILES)
	gcc $^ -I $(INCLUDE) -I $(INCLUDE_LIBFT) $(LIBRARY) -o $@

$(OBJECTS)/%.o: $(SOURCES_MAIN)/%.c
	gcc $(CCFLAGS) -c -I $(INCLUDE) -I $(INCLUDE_LIBFT) $< -o $@

$(OBJECTS)/%.o: $(SOURCES_LIST)/%.c
	gcc $(CCFLAGS) -c -I $(INCLUDE) -I $(INCLUDE_LIBFT) $< -o $@

$(OBJECTS)/%.o: $(SOURCES_NUMBERS)/%.c
	gcc $(CCFLAGS) -c -I $(INCLUDE) -I $(INCLUDE_LIBFT) $< -o $@

$(OBJECTS)/%.o: $(SOURCES_OPERATIONS)/%.c
	gcc $(CCFLAGS) -c -I $(INCLUDE) -I $(INCLUDE_LIBFT) $< -o $@

$(OBJECTS)/%.o: $(SOURCES_UTILS)/%.c
	gcc $(CCFLAGS) -c -I $(INCLUDE) -I $(INCLUDE_LIBFT) $< -o $@

$(OBJECTS)/%.o: $(SOURCES_SORT)/%.c
	gcc $(CCFLAGS) -c -I $(INCLUDE) -I $(INCLUDE_LIBFT) $< -o $@

$(OBJECTS)/%.o: $(SOURCES_PARSING)/%.c
	gcc $(CCFLAGS) -c -I $(INCLUDE) -I $(INCLUDE_LIBFT) $< -o $@

clean:
	rm -f $(OBJECTS_FILES)
	$(MAKE) clean -C src/libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C src/libft

re: fclean all
