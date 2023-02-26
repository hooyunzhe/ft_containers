SRC		= main.cpp tests/utils/utils.cpp tests/vector_test.cpp

ifeq (${OS}, Windows_NT)
NAME	= ft_containers.exe
CPP	= g++
RM	= del
else
NAME	= ft_containers
CPP		= c++ -std=c++98
RM		= rm -f
endif
CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

${NAME}:
	${CPP} ${CFLAGS} ${SRC} -o ${NAME}

test:	re
	./${NAME}

clean:
	${RM} ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
