NAME =		push_swap

CFLAGS =	-Wall -Werror -Wextra -g3 -fsanitize=address

CC =		gcc

MAKE =		make

LIBSDIR =	libft/

FILES =	ft_check.c            \
		ft_index.c            \
		ft_list.c             \
		ft_push_swap.c        \
		ft_push.c             \
		ft_radix.c            \
		ft_reverse_rotate.c   \
		ft_rotate.c           \
		ft_swap.c             \
		debug.c               \
		ft_tri_under_5.c      \
		ft_3_4_5.c            \

OBJ = ${FILES:.c=.o}

all :	libs ${NAME}

libs :
		${MAKE} -C ${LIBSDIR}

${NAME} : 	${OBJ} ${LIBSDIR}libft.a
				${CC} ${CFLAGS} -Llibft/ ${OBJ} -o push_swap -lft

%.o:			%.c ft_push_swap.h ${LIBSDIR}libft.h
				${CC} ${CFLAGS} -Ilibft/ -c $<

clean :
				${MAKE} clean -C ${LIBSDIR}
				rm -f ${OBJ} ${OBJ_B} 

fclean :
				${MAKE} fclean -C ${LIBSDIR}
				rm -f ${OBJ} ${OBJ_B} 
				rm -f ${NAME}

re :			fclean all

.PHONY:			all clean fclean bonus libs re