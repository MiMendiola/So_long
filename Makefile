NAME = so_long

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -framework OpenGL -framework AppKit
CC = cc
AR = ar -crs
RM = rm -f

LIBFTA = libft_ext/libft.a
MLXA = mlx/libmlx.a

SRCS = $(addprefix ./src/, parse_map/map_parse.c main.c message.c)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make all -sC ./libft_ext
	@echo "$(GREEN)Compiling Libft.$(CLEAR)"
	@make all -sC ./mlx
	@echo "$(GREEN)Compiling Mlx.$(CLEAR)"



	@$(CC) $(CFLAGS) $(OBJS) -I ./src/so_long.h $(LIBFTA) $(MLXA) $(MLXFLAGS) -o $(NAME)


	@echo "$(GREEN)So_long Compiled.$(CLEAR)"

clean:
	@$(RM) $(OBJS)
	@make clean -sC libft_ext
	@make clean -sC mlx
	@echo "$(RED)All Objs Deleted.$(CLEAR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFTA)
	@echo "$(RED)Everything Deleted.$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re