FT_NAME = ft_containers
STD_NAME = std_containers

FT_SRC = ft_main.cpp
STD_SRC = std_main.cpp

FT_OBJ = ${FT_SRC:.cpp=.o}
STD_OBJ = ${STD_SRC:.cpp=.o}

INC = -I./map -I./stack -I./utils -I./vector

CC = c++ ${CFLAGS}

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

.cpp.o:
	${CC} ${INC} -c $< -o ${<:.cpp=.o}

all: ${FT_NAME} ${STD_NAME}

${FT_NAME}: ${FT_OBJ}
	${CC} -o ${FT_NAME} ${FT_OBJ}

${STD_NAME}: ${STD_OBJ}
	${CC} -o ${STD_NAME} ${STD_OBJ}

clean:
	${RM} ${FT_OBJ} ${STD_OBJ}

fclean: clean
	${RM} ${FT_NAME} ${STD_NAME}

re: fclean all

.PHONY: all clean fclean re
