SRC =		src/main.c					\
			src/ft_atoi.c				\
			src/ft_init_forks.c			\
			src/ft_msleep.c				\
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

NAME	=	philosophers

NAME_B	=	philosophers_bonus

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

.PHONY:		all clean fclean re bonus