# Simple Shell Project Makefile

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Source and object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Executable name
NAME = hsh

# Default target
all: $(NAME)

# Compile the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean object files and executable
fclean: clean
	rm -f $(NAME)

# Clean and recompile
re: fclean all

# Run the shell
run: $(NAME)
	./$(NAME)

# Check for memory leaks
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Targets that don't create files
.PHONY: all clean fclean re run valgrind
