NAME =		push_swap

CFLAGS =	-Wall -Werror -Wextra

GCC =		gcc

MAKE =		make

LIBSDIR =	./libft/

FILES =	ft_check.c            \
		ft_index.c            \
		ft_list.c             \
		ft_push_swap.c        \
		ft_push.c             \
		ft_radix.c            \
		ft_reverse_rotate.c   \
		ft_rotate.c           \
		ft_swap.c             \

OBJ = ${FILES:.c=.o}

all :	libs ${NAME}

libs :
		${MAKE} -C ${LIBSDIR}

${NAME} : 	${OBJ} ${LIBSDIR}libft.a
				${GCC} ${FLAGS} -L${LIBSDIR} -lft ${OBJ} -o push_swap

%.o:			%.c push_swap.h
				$(GCC) $(CFLAGS) -c $< -o $@

clean :
				${MAKE} clean -C ${LIBSDIR}
				rm -f ${OBJ} ${OBJ_B} 

fclean :
				${MAKE} fclean -C ${LIBSDIR}
				rm -f ${OBJ} ${OBJ_B} 
				rm -f ${NAME}

re :			fclean all

.PHONY:			all clean fclean bonus libs re