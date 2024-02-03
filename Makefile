NAME = so_long

CFLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -crs
RM = rm -f

LIBFTA = libft_ext/libft.a
MLXA = mlx/libmlx.a

SRCS = map_parse.c

OBJS = $(SRCS:.c=.o)

all : makes_files $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

makes_files:
	@make all -C ./libft_ext
	@make all -sC ./mlx
	
clean:
	$(RM) $(OBJS)
	@make clean -C libft_ext
	@make clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFTA)

re: fclean all

.PHONY: all clean fclean re