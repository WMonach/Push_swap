NAME =		push_swap

SFLAG  =	-fsanitize=address -g3

CFLAGS =	-Wall -Werror -Wextra -I .

CC =		gcc

LIBSDIR =	libft/

OBJS_DIR = .objs

FILES =	check/ft_check.c				\
		check/ft_parse.c				\
		free/ft_free.c					\
		operations/ft_push.c			\
		operations/ft_reverse_rotate.c	\
		operations/ft_rotate.c			\
		operations/ft_swap.c			\
		set_up/ft_index.c				\
		set_up/ft_list.c				\
		tri/ft_3_4_5.c					\
		tri/ft_already_sort.c			\
		tri/ft_radix.c					\
		tri/ft_tri_under_5.c			\
		debug.c							\
		ft_push_swap.c

OBJ = $(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

all :	libs ${NAME}

libs :
		${MAKE} -C ${LIBSDIR}

${NAME} : 	${OBJ} ${LIBSDIR}libft.a
				${CC} ${CFLAGS} $(SFLAG) -Llibft/ ${OBJ} -o push_swap -lft

$(OBJS_DIR)/%.o:	%.c ft_push_swap.h ${LIBSDIR}libft.h ${LIBSDIR}libft.a Makefile
				mkdir -p $(dir $@)
				${CC} ${CFLAGS} -Ilibft/ -c $< -o $@

clean :
				${MAKE} clean -C ${LIBSDIR}
				rm -f ${OBJ} ${OBJ_B} 

fclean :
				${MAKE} fclean -C ${LIBSDIR}
				rm -f ${OBJ} ${OBJ_B} 
				rm -f ${NAME}

re :			fclean all

.PHONY:			all clean fclean bonus libs re