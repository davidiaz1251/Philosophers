# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
CLEAR	=	\033[0m

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -g3
SRC = ./src/main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@echo "$(YELLOW)Compiling philo...$(CLEAR)"
	@$(CC) $(CFLAGS)  -o $(NAME) $(OBJ)
	@echo "$(GREEN)philo compiled!$(CLEAR)"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)philo objects removed!$(CLEAR)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)philo removed!$(CLEAR)"

re: fclean $(NAME)

run: all
	@clear
	@./$(NAME)


# Descomment the line to get leaks
VALGRIND_FLAGS=#--leak-check=full
valgrind: all
	@clear
	@valgrind $(VALGRIND_FLAGS) ./$(NAME)

.PHONY: all clean fclean re