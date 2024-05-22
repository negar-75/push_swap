NAME = push_swap

CC = cc
CFLAGS = -g  -Werror
RM = rm -f
CLIBS = -L$(FT_PRINTF_FOLDER) -lftprintf -lm


SRC_FOLDER = src/
UTILS_FOLDER = utils/
FT_PRINTF_FOLDER = libs/ft_printf/

FT_PRINTF = $(FT_PRINTF_FOLDER)libftprintf.a
SRCS = $(SRC_FOLDER)main.c
UTILS = $(addprefix $(UTILS_FOLDER), \
	err_message.c \
	stack_utils.c \
	stack.c \
	str_funcs.c \
	validate_input.c)
ALL_SRCS = $(SRCS) $(UTILS)
OBJS = $(ALL_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(FT_PRINTF_FOLDER)
	$(CC) $(CFLAGS) $(OBJS) $(CLIBS) -o $(NAME)
	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(FT_PRINTF_FOLDER)