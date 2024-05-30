LIBC =	ft_atoi.c ft_strlen.c ft_strjoin.c

SRCS = ${LIBC}

SRCSALL = ${LIBC}

OBJS = ${SRCS:.c=.o}

OBJSALL = ${SRCSALL:.c=.o} 

LIB = libft.a

CC = gcc	

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}:	${OBJS}
		ar -rsc ${LIB} ${OBJS}

all: 	${LIB}

clean:	
		rm -f ${OBJSALL}

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCSALL)
	gcc -nostartfiles -shared -o libft.so $(OBJSALL)

.PHONY: all clean fclean re