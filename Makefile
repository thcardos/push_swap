NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude -Ilibft -Ift_printf
RM = rm -f

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/errors.c \
		$(SRC_DIR)/stack_init.c \
		$(SRC_DIR)/stack_ops_a.c \
		$(SRC_DIR)/stack_ops_b.c \
		$(SRC_DIR)/stack_ops_both.c \
		$(SRC_DIR)/stack_ops_helpers.c \
		$(SRC_DIR)/sort_small.c \
		$(SRC_DIR)/sort_big.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/utils_cost.c \
		$(SRC_DIR)/utils_cost_exec.c 
		
BONUS_SRCS = $(SRC_DIR)/checker_bonus.c \
        $(SRC_DIR)/parsing.c \
        $(SRC_DIR)/errors.c \
        $(SRC_DIR)/stack_init.c \
        $(SRC_DIR)/stack_ops_a.c \
        $(SRC_DIR)/stack_ops_b.c \
        $(SRC_DIR)/stack_ops_both.c \
		$(SRC_DIR)/stack_ops_helpers.c \
        $(SRC_DIR)/utils.c \
		$(SRC_DIR)/utils_cost.c \
		$(SRC_DIR)/utils_cost_exec.c 

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(BONUS_NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
