NAME = philo

SRCS = 		main.c \
			parser.c \
			utils.c \
			life_cycle.c \
			philo.c

#OBJ = $(patsubst %.c, %.o, $(SRC))

INCLUDE = philo.h

FLAGS = #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(INCLUDE) $(SRCS)
			gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:
			rm -f $(OBS)

fclean: #clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
