NAME = ft_containers

SRC = std_main.cpp

OBJ = ${SRC:.cpp=.o}

INC = -I./map -I./stack -I./utils -I./vector

CC = c++ ${CFLAGS}

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

.cpp.o:
	${CC} ${INC} -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJ}
	${CC} -o ${NAME} ${OBJ}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
