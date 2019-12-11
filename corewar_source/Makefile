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
COREWAR = corewar

HEADERS = -I includes/
FLAGS = -Wall -Wextra -Werror

SRC_FOLDER = src
OBJ_FOLDER = obj

SRC_NAMES = main.c for_parsing_champ.c init_global_state.c parse_arguments.c \
    parse_champion_file.c parse_flags.c parsing_champ.c print_error.c main_alg.c \
    init_arena.c free_all.c cursor_operations.c visualisation.c

ASM_SRC = $(addprefix $(SRC_FOLDER)/, $(SRC_NAMES))

OBJ = $(addprefix $(OBJ_FOLDER)/, $(SRC_NAMES:.c=.o))

all: $(LIBFT_PATH) $(COREWAR)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	@gcc $(FLAGS) $(HEADERS) -c $< -o $@
	@echo "Obj -> done"

$(LIBFT_PATH):
	@make -C $(LIBFT)
	@echo "Library -> done"

$(COREWAR): $(OBJ)
	@gcc $(OBJ) $(HEADERS) -L. $(LIBFT_PATH) -o $(COREWAR)
	@echo "Corewar binary -> done"

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -rf $(OBJ_FOLDER)
	@echo "Obj removed"

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(COREWAR)
	@echo "Binaries removed"

re: fclean all

