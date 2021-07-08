NAME= push_swap

ARRAY_LIST = ./lib/arraylist/libarraylist.a

ARRAY_LIST_INC = ./lib/arraylist/includes/

INC= ./headers/ -I $(ARRAY_LIST_INC)

SRC= ./src/init.c ./src/push_swap.c ./src/push.c ./src/reverse_rotate.c ./src/rotate.c ./src/swap.c  ./src/utils.c ./src/check.c

FLAGS = -Wall -Wextra -Werror -g 


all: $(NAME)


$(NAME): array_list
	gcc $(FLAGS) $(SRC) $(ARRAY_LIST) -I $(INC) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all


array_list:
	make -C ./lib/arraylist/

