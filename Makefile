SRCS	=	algo.c algo_bis.c push_swap.c instructions.c \
			instructions_bis.c instructions_ter.c \
			ft_split.c funcs.c funcs_bis.c 

OBJS	=	${SRCS:.c=.o}

NAME		=	push_swap

CFLAGS	= -Wall -Wextra -Werror -g3 -I ./

CC		= cc

RM		= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# ${NAME}: ${OBJS}
# 		ar -rcs ${NAME} ${OBJS}
${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re bonus



