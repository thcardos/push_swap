NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_OBJECTS = $(LIBFT_DIR)/*.o

SOURCES = ft_printf.c \
			ft_print_char.c \
			ft_print_str.c \
			ft_print_int.c \
			ft_print_uint.c \
			ft_print_hex.c \
			ft_print_ptr.c \
			

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS) $(LIBFT_OBJECTS)
	ranlib $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
