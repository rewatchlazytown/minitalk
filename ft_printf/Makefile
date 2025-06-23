NAME	= libftprintf.a

SRCS	= ft_unsigned.c ft_hex.c ft_pointer.c ft_string.c ft_printf_put.c ft_printf.c

OBJS	= $(SRCS:.c=.o)

HEADER  = ft_printf.h

FLAGS	= -Wall -Wextra -Werror

%.o : %c
	gcc $(FLAGS) -c $< -I$(HEADER) -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
