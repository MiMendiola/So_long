NAME = so_long
NAME_BONUS = so_long_bonus

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
MLXFLAGS = -framework OpenGL -framework AppKit
CC = cc
AR = ar -crs
RM = rm -f

LIBFTA = libft_ext/libft.a
MLXA = mlx/libmlx.a

SRCS = $(addprefix ./src/, so_long.c \
		game/game.c game/message.c game/movements.c\
		map/map_read.c map/map_checker.c \
		sprites/sprite_creator.c sprites/sprite_generator.c sprites/frames_charger.c)

SRCS_BONUS = $(addprefix ./bonus/, so_long.c \
		game/game.c game/message.c game/movements.c\
		map/map_read.c map/map_checker.c \
		sprites/sprite_creator.c sprites/sprite_covers.c sprites/sprite_generator.c sprites/frames_charger.c)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	@make all -sC ./libft_ext
	@echo "$(GREEN)Compiling Libft.$(CLEAR)"
	@make all -sC ./mlx
	@echo "$(GREEN)Compiling Mlx.$(CLEAR)"
	@$(CC) $(CFLAGS) $(OBJS) -I ../../includes/so_long.h $(LIBFTA) $(MLXA) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)So_long Compiled.$(CLEAR)"

$(NAME_BONUS) : $(OBJS_BONUS)
	@make all -sC ./libft_ext
	@echo "$(GREEN)Compiling Libft.$(CLEAR)"
	@make all -sC ./mlx
	@echo "$(GREEN)Compiling Mlx.$(CLEAR)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -I ../../includes/so_long.h $(LIBFTA) $(MLXA) $(MLXFLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)So_long Bonus Compiled.$(CLEAR)"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@make clean -sC libft_ext
	@make clean -sC mlx
	@echo "$(RED)All Objs Deleted.$(CLEAR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) $(LIBFTA)
	@echo "$(RED)Everything Deleted.$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re