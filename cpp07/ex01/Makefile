NAME = template

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

SRCS_PATH = ./srcs
OBJS_PATH = ./obj

SRCS =	main.cpp

OBJS = $(addprefix $(OBJS_PATH)/, $(SRCS:.cpp=.o))

PURPLE := \033[95m
GREEN := \033[92m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(PURPLE)"
	@echo "  ██████╗  ██████╗   ██████╗"
	@echo "  ██╔═══   ██   ██║  ██   ██║"
	@echo "  ██║      ██████╔╝  ██████╔╝"
	@echo "  ██║      ██╔═══╝   ██╔═══╝"
	@echo "  ██████║  ██║       ██║"
	@echo "  ╚═════╝  ╚═╝       ╚═╝"
	@echo "Creating $(NAME)..."
	@echo "$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.cpp
	@mkdir -p $(OBJS_PATH)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(PURPLE)"
	@echo "Cleaning object files..."
	@echo "$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(PURPLE)"
	@echo "Cleaning $(NAME)..."
	@echo "$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
