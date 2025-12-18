# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 12:25:45 by gangel-a          #+#    #+#              #
#    Updated: 2025/12/17 21:05:31 by gangel-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = claptrap

# COMPILER
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

# DIRECTORIES
OBJ_DIR = bin/

# SOURCE
SRC := main.cpp \
	ClapTrap.cpp
OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)

# ------------------------------ Colors ------------------------------

BLUE		=	\033[0;34m
BLUE_BOLD	=	\033[1;34m
GREEN_BOLD	=	\033[1;92m
YELLOW_BOLD	=	\033[1;93m
YELLOW		=	\033[0;33m
RED			=	\033[0;91m
MAGENTA 	=	\033[1;35m
MAGENTA_BOLD = \033[1;35m
CYAN		=	\033[0;96m
CYAN_BOLD	=	\033[1;36m
RESET		=	\033[0m

# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@
	@printf "$(GREEN_BOLD)Compilation successful: $(NAME) $(RESET)\n"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(MAGENTA_BOLD)[$(NAME)]:\tobject files$(RESET)$(GREEN_BOLD)  => Cleaned!$(RESET)\n"
fclean: clean
	@rm -f $(NAME)
	@printf "$(MAGENTA_BOLD)[$(NAME)]:\texec. files$(RESET)$(GREEN_BOLD)  => Cleaned!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re