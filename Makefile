# *--------- SOURCES ---------* 

SRCS_DIR = ./srcs/
SRCS = main.c								\
	init/check_errors.c						\
	init/get_args.c							\
	init/init_mutex.c						\
	init/init_philo.c						\
	init/init_threads.c						\
	routine/check_death.c					\
	routine/check_is_alive.c				\
	routine/display.c						\
	routine/philo_eat.c						\
	routine/routine.c						\
	utils/free4yourlife.c					\
	utils/ft_atoi.c							\
	utils/ft_isdigit.c						\
	utils/ft_strlen.c						\
	utils/get_time.c						\
	utils/join_threads.c					\
		
OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

# *--------- includes ---------* 

INCLUDES_DIR = -I ./includes
INC = ./includes/philosophers.h

# *--------- OTHERS ---------*

NAME = philo

CC = clang
RM = rm -f

CFLAGS = -g -Wall -Wextra -Werror -pthread
# CFLAGS = -Wall -Wextra -Werror -pthread -g3 -fsanitize=thread

# *========= RULES =========*

all:		$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES_DIR) 

$(NAME):	$(OBJS) $(INC)
	        $(CC) $(CFLAGS) $(OBJS) $(INCLUDES_DIR) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re