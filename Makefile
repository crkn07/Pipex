# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 20:21:27 by crtorres          #+#    #+#              #
#    Updated: 2023/03/01 21:56:48 by crtorres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #
#
GREEN 	= @echo "\033[0;32m"
BLUE 	= @echo "\033[0;34m"
PURPLE 	= @echo "\033[0;35m"
CYAN 	= @echo "\033[0;36m"
RESET 	= "\033[1;0m"

NAME = pipex
NAME_BONUS = pipex_bonus


SRC_PATH = ./src/

SRC_B_PATH = ./src_bonus/

INC = ./includes/

INC_BONUS = ./includes_bonus/

DOT_O = _objFiles/

LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I inc -I libft

SRC = main.c pipex_utils.c\

SRC _B = main_bonus.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRCS_BONUS = $(addprefix $(SRC_B_PATH), $(SRC_B))

OBJS =  $(addprefix $(DOT_O)/, $(SRC:%.c=%.o))

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

##bonus: $(NAME_BONUS)
$(DOT_O):
	@mkdir -p $(DOT_O)

$(DOT_O)/%.o: $(SRC_PATH)/%.c | $(DOT_O)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -sC ./libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	clear
	$(GREEN) "\n👍🏽pipex succesfully compiled!👍🏽\n " $(RESET)

##$(NAME_BONUS): $(OBJS_BONUS)
##	@make -C ./libft
##	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
##	@echo "👍🏾pipex_bonus succesfully compiled!👍🏾"

clean:
	$(PURPLE) CLEANING... $(RESET)
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rm -rf $(DOT_O)
	$(PURPLE) CLEANING libft... $(RESET)
	@make clean -C ./libft
	$(GREEN) "CLEAN COMPLETE" $(RESET)

fclean: clean

re: fclean all

reb: fclean bonus

.PHONY: all clean fclean re reb bonus