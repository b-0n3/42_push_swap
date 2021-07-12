# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 19:11:19 by aait-ham          #+#    #+#              #
#    Updated: 2021/07/11 19:11:21 by aait-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

ARRAY_LIST = ./lib/arraylist/libarraylist.a

ARRAY_LIST_INC = ./lib/arraylist/includes/
UTILS= ./lib/utils/src/utils.c ./lib/utils/src/utils2.c ./lib/utils/src/utils3.c
UTILS_INC = ./lib/utils/includes
INC= ./headers/ -I $(ARRAY_LIST_INC)  -I $(UTILS_INC)

GNL_INC= ./lib/getnextline/includes	
GNL_SRC= ./lib/getnextline/src/*.c
SRC= ./src/check.c \
		./src/check_input.c  \
		./src/chunk.c \
		./src/clone_and_sort.c \
		./src/filter_chunks.c \
		./src/find_elements.c \
		./src/init.c \
		./src/push.c \
		./src/push_swap.c \
		./src/push_to.c \
		./src/reverse_rotate.c  \
		./src/rotate.c \
		./src/sort.c \
		./src/sort_tree.c \
		./src/swap.c $(UTILS)

FLAGS = -Wall -Wextra -Werror -g 

CHECKER = checker
CHECKER_INC = ./checkerfiles/include/  -I $(INC) -I $(GNL_INC)

CHECKER_SRC = ./checkerfiles/src/*.c ./src/check_input.c \
./src/check.c ./src/init.c ./src/push.c \
 ./src/reverse_rotate.c ./src/rotate.c ./src/swap.c $(GNL_SRC) $(UTILS) ./src/chunk.c

all: $(NAME)


$(NAME): array_list
	gcc $(FLAGS) $(SRC) $(ARRAY_LIST) -I $(INC) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all


checker: 
	gcc  $(CHECKER_SRC) $(ARRAY_LIST) -I $(CHECKER_INC) -o $(CHECKER)

checker_re: checker_fclean checker


checker_fclean:
	rm -rf $(CHECKER)

array_list:
	make -C ./lib/arraylist/

