NAME = push_swap

CC = cc
CFLAGS = -g  -Wall -Wextra -Werror
RM = rm -f
CLIBS = -L$(FT_PRINTF_FOLDER) -lftprintf -lm


SRC_FOLDER = src/
UTILS_FOLDER = utils/
INSTRUCTIONS_FOLDER = instructions/
FT_PRINTF_FOLDER = libs/ft_printf/
FT_PRINTF = $(FT_PRINTF_FOLDER)libftprintf.a

SRCS = $(addprefix $(SRC_FOLDER), \
	main.c \
	simple_sort/simple_sort.c \
	simple_sort/sort_3.c \
	algorithm/algorithm_utils.c \
	algorithm/apply_rotation.c \
	algorithm/big_sort.c \
	algorithm/calculate_cost.c \
	algorithm/rotate.c )

UTILS = $(addprefix $(UTILS_FOLDER), \
	err_message.c \
	stack_utils.c \
	stack.c \
	str_funcs.c \
	validate_input.c)

INSTRUCTIONS = $(addprefix $(INSTRUCTIONS_FOLDER), \
	push.c \
	reverse_rotate.c \
	rotate.c \
	swap.c)

ALL_SRCS = $(SRCS) $(UTILS) $(INSTRUCTIONS)

OBJS = $(ALL_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(FT_PRINTF_FOLDER)
	$(CC) $(CFLAGS) $(OBJS) $(CLIBS) -o $(NAME)
	

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(FT_PRINTF_FOLDER)

fclean: clean
	@$(MAKE) fclean -C $(FT_PRINTF_FOLDER)
	$(RM) $(NAME)

re: clean all