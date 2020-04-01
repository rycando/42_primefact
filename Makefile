SRCS = ./factorization.c

OBJS = $(SRCS:.c=.o)

NAME = factorization

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all : $(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lm

clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re