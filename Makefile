NAME	= ft_containers

SRC		= main.cpp
SRC_PDF	= main_pdf.cpp

CPP		= c++ -std=c++98
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:	${NAME}

${NAME}:
	${CPP} ${CFLAGS} ${SRC} -o ${NAME}

pdf:
	${CPP} ${CFLAGS} ${SRC_PDF} -o ${NAME}

clean:
	${RM} ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re