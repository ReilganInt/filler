# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmormont <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 22:13:58 by vmormont          #+#    #+#              #
#    Updated: 2019/06/01 19:58:05 by vmormont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

SRC_DIR	= ./src
INC_DIR = ./include
OBJ_DIR = ./obj

RAW_SRC	:= $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")
RAW_DIRS:= $(shell find $(SRC_DIR) -type d -mindepth 1)
SRCDIRS = $(RAW_DIRS:./src/%=%)
SRC		= $(RAW_SRC:./src/%=%)
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(addprefix $(OBJ_DIR)/,$(SRCDIRS))

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all
