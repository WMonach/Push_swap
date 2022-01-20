NAME =		push_swap.a

CFLAGS =	-Wall -Werror -Wextra

GCC =		gcc -o

MAKE =		make

LIBSDIR =	./libft

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

libs :
		${MAKE} -C ${LIBSDIR}

all :	${NAME}

push_swap.a : 	${OBJ}
				ar rc ${NAME} ${OBJ}

%.o:			%.c push_swap.h
				$(GCC) $(CFLAGS) -c $< -o $@ push_swap

clean :
				rm -f ${OBJ} ${OBJ_B}

fclean :		clean
				rm -f ${NAME}

re :			fclean all

.PHONY:			all clean fclean bonus push_swap.a .c.o re