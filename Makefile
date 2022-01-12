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

clean : 