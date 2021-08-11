NAME = philo

SRCS = 		main.c \
			parser.c \
			utils.c \
			life_cycle.c \
			philo.c \
			utils_part_two.c

OBJ = $(patsubst %.c, %.o, $(SRCS))

INCLUDE = philo.h

FLAGS = #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
			gcc $(FLAGS) $(OBJ) -pthread -o $(NAME)

clean:
			rm -rf $(OBJ)

fclean: clean
			rm -rf $(NAME)

re: fclean all

norm:
			norminette $(SRCS)
			norminette $(INCLUDE)

.PHONY: all clean fclean re
