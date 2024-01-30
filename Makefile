NAME = so_long

CFLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -crs
RM = rm -f

SRCS = so_long.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re