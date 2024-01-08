NAME = push_swap
PRF =  $(PRF_DIR)libftprintf.a

PRF_DIR = ./printf/
SRC_DIR = ./src/
INC_DIR = ./includes/

SRC = main\
sort\
sort_tiny\
sort_utils\
initialized\
check_inputs\
check_inputs_utils\
assign_index\
ope_package/swap\
ope_package/push\
ope_package/rotate\
ope_package/reverse\


SRCS = $(addprefix ${SRC_DIR}, $(addsuffix .c, ${SRC}))

OBJB = $(SRCS:.c=.o)

CC = gcc

CFLAG = -Wall -Werror -Wextra

.c.o :
	@$(CC) $(CFLAG) -c -I $(INC_DIR) -I $(PRF_DIR) $< -o $@

all : $(NAME)

$(NAME) : $(OBJB) $(PRF)
	@$(CC) $(CFLAG) $(OBJB) $(PRF) -o $(NAME)

$(PRF) : 
	@make -C $(PRF_DIR)

clean :
		rm -f $(OBJB) $(B_OBJB) && make -C $(PRF_DIR) clean

fclean : clean
		rm -f $(NAME) && make -C $(PRF_DIR) fclean

re : clean fclean all