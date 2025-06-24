# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 15:35:03 by gangel-a          #+#    #+#              #
#    Updated: 2025/06/24 15:42:54 by gangel-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = megaphone

# COMPILER
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

# SOURCE
SRC = megaphone.cpp

# RULES
all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@printf "\033[32m%s\033[0m\n" "Compilation successful: $(NAME)"

clean:
	@rm -f $(NAME)
	@printf "\033[33m%s\033[0m\n" "Cleaned up: $(NAME)"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[31m%s\033[0m\n" "Fully cleaned: $(NAME)"

re: fclean all

.PHONY: all clean fclean re