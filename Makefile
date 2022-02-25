NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = ./src/ft_printf.c ./src/parser.c ./src/converter.c ./src/composer.c ./src/printer.c ./src/utils.c
LIBS = libft.a
INCS = ./include
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@make -C ./libft
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)

.c.o:
	${CC} ${FLAGS} -I ${INCS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}
	make clean -C ./libft

fclean: clean
	rm -f ${NAME}
	make fclean -C ./libft

re: fclean all

# test:
#	bash test.sh

.PHONY: all bonus clean fclean re test f p