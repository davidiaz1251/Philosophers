# Makefile silencioso
NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -Iinclude

SRCS = \
	src/main.c \
	src/init/parse_args.c \
	src/init/init_structs.c \
	src/simulation/philosopher.c \
	src/simulation/monitor.c \
	src/simulation/routine.c \
	src/utils/ft_atoi.c \
	src/utils/ft_isdigit.c \
	src/utils/time_utils.c \
	src/utils/print_utils.c \
	src/utils/free_split.c \
	src/utils/ft_split.c \
	src/utils/ft_substr.c \
	src/utils/ft_strlen.c \
	src/utils/ft_strdup.c \
	src/utils/validate.c \
	src/cleanup/free_all.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re