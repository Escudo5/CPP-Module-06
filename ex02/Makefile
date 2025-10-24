NAME = ex02

SRC = main.cpp Base.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "[ex02] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[ex02] Executable cleaned."

re: fclean all

.PHONY: all clean fclean re