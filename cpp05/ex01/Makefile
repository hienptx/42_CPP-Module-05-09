NAME := Bureaucrat

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17

SRC := main.cpp Bureaucrat.cpp Form.cpp
OBJ := $(SRC:.cpp=.o)

PURPLE := \033[95m
GREEN := \033[92m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(PURPLE)"
	@echo "  ██████╗  ██████╗   ██████╗"
	@echo "  ██╔═══   ██   ██║  ██   ██║"
	@echo "  ██║      ██████╔╝  ██████╔╝"
	@echo "  ██║      ██╔═══╝   ██╔═══╝"
	@echo "  ██████║  ██║       ██║"
	@echo "  ╚═════╝  ╚═╝       ╚═╝"
	@echo "Creating $(NAME)..."
	@echo "$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(PURPLE)"
	@echo "Cleaning object files..."
	@echo "$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(PURPLE)"
	@echo "Cleaning $(NAME)..."
	@echo "$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
