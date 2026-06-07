# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/09 18:38:14 by sarayapa          #+#    #+#              #
#    Updated: 2026/06/07 18:11:35 by sarayapa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

FILES = philo_main.c philo_parser.c philo_utils.c philo_activities.c philo_checking.c

SRCS = src/
BUILD = build/
INC = -Iinclude

SRCS_O = $(addprefix $(BUILD), $(FILES:.c=.o))

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
BLUE = \033[1;34m
WHITE = \033[1m
RESET = \033[0m

all: $(BUILD) $(NAME)

$(BUILD):
	@mkdir -p $(BUILD)

$(BUILD)%.o: $(SRCS)%.c
	@echo "$(YELLOW)Compiling file...$(RESET)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(SRCS_O)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)✔ $(NAME) ready Location: $(BLUE)$$(pwd)/$(YELLOW)$(NAME)$(RESET)"

norm:
	@echo "========= INCLUDES =========="
	@norminette ./include
	@echo "========= SOURCES ==========="
	@norminette $(SRCS)

clean:
	@rm -rf $(BUILD)
	@echo "$(RED)Cleaned objects!$(RESET)"

fclean: clean
	@echo "$(RED)Removed $(NAME)!$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm 