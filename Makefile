# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/09 18:38:14 by sarayapa          #+#    #+#              #
#    Updated: 2026/04/10 11:15:12 by sarayapa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

FILES = philo_main.c philo_parser.c philo_utils.c philo_activities.c

SRCS = src/
BUILD = build/
INC = -Iinclude -Ilibft/include

SRCS_O = $(addprefix $(BUILD), $(FILES:.c=.o))

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
BLUE = \033[1;34m
WHITE = \033[1mlibmlx
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
	@make -s fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm 