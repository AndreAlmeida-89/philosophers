SRC =		src/main.c					\
			src/ft_atoi.c				\
			src/ft_init_forks.c			\
			src/ft_wait.c				\
			src/ft_routine.c			\
			src/ft_destroy.c			\
			src/ft_init_philosophers.c	\
			src/ft_now.c				\
			src/ft_start_threads.c		\
			src/ft_init_config.c		\
			src/ft_init_table.c			\
			src/ft_print_action.c		\
			src/ft_wait_threads.c		\


SRC_B 	= 	src_bonus/main_bonus.c		\

NAME	=	philo

NAME_B	=	philo_bonus

OBJ		=	$(SRC:%.c=%.o)

OBJ_B	=	$(SRC_B:%.c=%_b.o)

CC		=	cc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -pthread -fsanitize=thread -g

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

%_b.o: 		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_B):	$(OBJ_B)
			$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)

all:		$(NAME)

bonus:		$(NAME_B)

clean:
			$(RM) $(OBJ) $(OBJ_B)

fclean:		clean
			$(RM) $(NAME) $(NAME_B)

re:			fclean all

test1:	all
		@echo "The philosopher should not eat and should die."
		./$(NAME) 1 800 200 200

test2:	all
		@echo "No philosopher should die."
		./$(NAME) 5 800 200 200

test3:	all
		@echo "No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times."
		./$(NAME) 5 800 200 200 7

test4:	all
		@echo "No philosopher should die."
		./$(NAME) 4 410 200 200

test5:	all
		@echo "One philosopher should die."
		./$(NAME) 4 310 200 100

test6:	all
		@echo "Test with 2 philosophers and check the different times: a death delayed by more than 10 ms is unacceptable."
		./$(NAME) 2 410 200 200

.PHONY:		all clean fclean re bonus