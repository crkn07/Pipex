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

NAME = pipex
NAME_BONUS = pipex_bonus

SRC_PATH = ./src/

SRC_B_PATH = ./src_bonus/

INC = ./includes/

INC_BONUS = ./includes_bonus/

DOT_O = _objFiles/

LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I inc -I libft -g3

SRC = main.c pipex_utils.c\

SRC _B = main_bonus.c \

SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRCS_BONUS = $(addprefix $(SRC_B_PATH), $(SRC_B))

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

##bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	@make -sC ./libft
	@mkdir -p $(DOT_O)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@mv $(OBJS) $(DOT_O)
	@echo "👍🏽pipex succesfully compiled!👍🏽"

##$(NAME_BONUS): $(OBJS_BONUS)
##	@make -C ./libft
##	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
##	@echo "👍🏾pipex_bonus succesfully compiled!👍🏾"

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rm -rf $(DOT_O)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C ./libft

re: fclean all

reb: fclean bonus

.PHONY: all clean fclean re reb bonus