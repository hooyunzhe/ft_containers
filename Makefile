NAME	= ft_containers

SRC		= main.cpp

CPP		= c++ -std=c++98
CFLAGS	= -Wall -Wextra -Werror
# RM		= rm -f
RM		= del

all:	${NAME}

${NAME}:
	${CPP} ${CFLAGS} ${SRC} -o ${NAME}

test:	re
	./ft_containers

clean:
	${RM} ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
