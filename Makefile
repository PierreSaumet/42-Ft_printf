NAME		=	libftprintf.a

SRCS		=	srcs/ft_printf.c \
				srcs/ft_calculs.c \
				srcs/ft_flags.c \
				srcs/ft_init.c \
				srcs/ft_libft.c \
				srcs/ft_conv_cspp.c \
				srcs/ft_p.c	\
				srcs/ft_numbers.c \
				srcs/ft_conv_diuxx.c \
				srcs/ft_numbersx.c \
				srcs/ft_p_next.c	\
				srcs/ft_numbersxone.c	\
				srcs/ft_numbersxtwo.c	\
				srcs/ft_numbersxthree.c	\
				srcs/ft_numbersxfour.c	\
				srcs/ft_numberxfive.c	\
				srcs/ft_numberssix.c	\
				srcs/ft_numberseven.c	\
				srcs/ft_convone.c	\
				srcs/ft_convtwo.c	\
				srcs/ft_convthree.c	\


OBJS		=	${SRCS:.c=.o}
OBJSBO		=	${SRCSBO:.c=.o}
INCLUDES	=	includes/
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra

all:			$(NAME)

$(NAME):		${OBJS}
		ar rc	${NAME} ${OBJS}
		ranlib	${NAME}
.c.o:
		${CC} ${FLAGS} -I $(INCLUDES) -c $< -o ${<:.c=.o}
clean:
		/bin/rm -f srcs/*.o

fclean:	clean
		@$(RM) $(NAME)
		@rm -rf a.out a.out.dSYM

re:		fclean all

.PHONY:		all clean fclean re
