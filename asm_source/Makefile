# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swarner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 15:43:04 by swarner           #+#    #+#              #
#    Updated: 2019/11/13 15:43:06 by swarner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = lib
LIBFT_PATH = lib/libft.a
ASM = asm

HEADERS = -I includes/
FLAGS = -Wall -Wextra -Werror

SRC_FOLDER = src
OBJ_FOLDER = obj

SRC_NAMES = main.c parse.c error_exit.c \
			structs.c main_parse.c op.c \
			write_hex.c write_hex_exec_code.c

ASM_SRC = $(addprefix $(SRC_FOLDER)/, $(SRC_NAMES))

OBJ = $(addprefix $(OBJ_FOLDER)/, $(SRC_NAMES:.c=.o))

all: $(LIBFT_PATH) $(ASM)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	@gcc $(FLAGS) $(HEADERS) -c $< -o $@
	@echo "$< -> done"

$(LIBFT_PATH):
	@make -C $(LIBFT)
	@echo "$(LIBFT_PATH) -> done"

$(ASM): $(OBJ)
	@gcc $(OBJ) $(HEADERS) -L. $(LIBFT_PATH) -o $(ASM)
	@echo "Asm compilator binary -> done"

clean:
	@make clean -C $(LIBFT)
	/bin/rm -rf $(OBJ_FOLDER)
# 	@echo "Obj removed"

fclean: clean
	@make fclean -C $(LIBFT)
	/bin/rm -f $(ASM)
# 	@echo "Binaries removed"

re: fclean all