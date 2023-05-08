# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amonbaro <amonbaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 10:02:39 by amonbaro          #+#    #+#              #
#    Updated: 2023/05/08 08:15:43 by amonbaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********** Colors ********** #
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
PURPLE = \033[0;94m
# **************************** #

NAME	=	push_swap

SRC		=	src/main.c \
			src/00_inst_a.c \
			src/01_inst_b.c \
			src/02_inst_ab.c \
			src/03_utils.c \
			src/04_split.c \
			src/05_in_tab.c \
			src/06_p_to_stack.c \
			src/07_sort_4nb.c \
			src/08_sort_6nb.c \
			src/09_push_sort.c \

OBJ		=	$(SRC:.c=.o)

flags	=	-Wall -Wextra -Werror

%.o: %.c
			@gcc -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@gcc $(flags) $(SRC) -o $(NAME)
			@echo "$(GREEN)! COMPILED PUSH_SWAP !$(DEF_COLOR)"

clean:
			@rm -rf $(OBJ)
			@echo "$(YELLOW)! CLEANED OBJECT FILES !$(DEF_COLOR)"

fclean: clean
			@rm -rf $(NAME)
			@echo "$(RED)! ALL FILES CLEANED !$(DEF_COLOR)"

re: fclean all
			@echo "$(PURPLE)! ALL FILES CLEANED AND REBUILT !$(DEF_COLOR)"
