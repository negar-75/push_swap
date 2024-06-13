NAME = push_swap

CC = cc
CFLAGS = -g  -Wall -Wextra -Werror
RM = rm -f
CLIBS = -L$(FT_PRINTF_FOLDER) -lftprintf -lm


SRC_FOLDER = src/
UTILS_FOLDER = utils/
INSTRUCTIONS_FOLDER = instructions/
LIBSFUNCS_FOLDER = libs/


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

LIBSFUNCS = $(addprefix $(LIBSFUNCS_FOLDER), \
	ft_isdigit.c \
	ft_putchar.c \
	ft_putendl.c \
	ft_putstr.c  \
	ft_split.c   \
	ft_strlen.c  \
	ft_strncmp.c \
	ft_atoi.c)

ALL_SRCS = $(SRCS) $(UTILS) $(INSTRUCTIONS) $(LIBSFUNCS)

OBJS = $(ALL_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CLIBS) -o $(NAME)
	

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all