NAME = libft.a
BONUS_NAME = .bonus

CFLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar -crs
RM = rm -f

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c
SRCS_GNL = get_next_line.c get_next_line_utils.c
SRCS_PRINTF = ft_printf_basics.c ft_printf_others.c ft_printf.c
		
BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
	$(AR) $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)

$(BONUS_NAME) : $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF) $(BONUS_OBJS)
	$(AR) $(BONUS_NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF) $(BONUS_OBJS)

bonus : $(BONUS_NAME)
	
clean:
	$(RM) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re