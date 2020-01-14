# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swarner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 15:57:22 by swarner           #+#    #+#              #
#    Updated: 2019/11/13 15:57:23 by swarner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
COREWAR = corewar
ASM_SRC = asm_source
COREWAR_SRC = corewar_source

FLAGS = -Wall -Wextra -Werror

ASM_SRC_NAMES = main.c parse.c error_exit.c \
			structs.c main_parse.c op.c \
			write_hex.c tools.c switch_labels.c \
			tools2.c get_hex_exec_code.c char_struct_to_hex.c \
			tools3.c hex_tools.c tools4.c main_parse_tools.c args.c

ASM_LIBFT_PATH = asm_source/lib/libft.a
ASM_LIBFT = asm_source/lib

ASM_HEADERS = -I asm_source/includes/

ASM_SRC_FOLDER = asm_source/src
ASM_OBJ_FOLDER = asm_source/obj

ASM_SRC_CODE = $(addprefix $(ASM_SRC_FOLDER)/, $(ASM_SRC_NAMES))

ASM_OBJ = $(addprefix $(ASM_OBJ_FOLDER)/, $(ASM_SRC_NAMES:.c=.o))


COREWAR_SRC_NAMES = main.c \
			init.c \
    		parse_flags.c \
    		parse_champion_file.c \
    		parse_prog_args.c \
    		parse_op.c \
			read_and_check_champ_file.c \
    		put_players_in_order.c \
    		byte_shift.c \
    		print_error.c \
    		print_info.c \
    		main_alg.c \
    		init_arena.c \
    		free_all.c \
    		cursor_operations.c \
    		visualisation.c \
    		vis_prepare_map.c \
    		vis_tools.c \
    		vis_init.c \
    		vis_draw.c \
    		vis_draw_info.c \
    		op.c \
    		do_operations.c \
    		op_args_validation.c \
    		exactly_do.c \
    		add_sub.c \
    		aff.c \
    		and_or_xor.c \
    		fork_lfork.c \
    		ld_ldi_lld_lldi.c \
    		st_sti.c \
    		zjmp.c \
    		live.c

COREWAR_LIBFT_PATH = corewar_source/lib/libft.a
COREWAR_LIBFT = corewar_source/lib

COREWAR_HEADERS = -I corewar_source/includes/

COREWAR_SRC_FOLDER = corewar_source/src
COREWAR_OBJ_FOLDER = corewar_source/obj

COREWAR_SRC_CODE = $(addprefix $(COREWAR_SRC_FOLDER)/, $(COREWAR_SRC_NAMES))

COREWAR_OBJ = $(addprefix $(COREWAR_OBJ_FOLDER)/, $(COREWAR_SRC_NAMES:.c=.o))

all: $(ASM_LIBFT_PATH) $(ASM) $(COREWAR_LIBFT_PATH) $(COREWAR)

$(ASM_OBJ_FOLDER)/%.o: $(ASM_SRC_FOLDER)/%.c
	@mkdir -p $(ASM_OBJ_FOLDER)
	@gcc $(FLAGS) $(ASM_HEADERS) -c $< -o $@
	@echo "$< -> done"

$(ASM_LIBFT_PATH):
	@make -C $(ASM_LIBFT)
	@echo "$(ASM_LIBFT_PATH) -> done"

$(ASM): $(ASM_OBJ)
	@gcc $(ASM_OBJ) $(ASM_HEADERS) -L. $(ASM_LIBFT_PATH) -o $(ASM)
	@echo "Asm compilator binary -> done"

$(COREWAR_OBJ_FOLDER)/%.o: $(COREWAR_SRC_FOLDER)/%.c
	@mkdir -p $(COREWAR_OBJ_FOLDER)
	@gcc $(FLAGS) $(COREWAR_HEADERS) -c $< -o $@
	@echo "$< -> done"

$(COREWAR_LIBFT_PATH):
	@make -C $(COREWAR_LIBFT)
	@echo "$(COREWAR_LIBFT_PATH) -> done"

$(COREWAR): $(COREWAR_OBJ)
	@gcc $(COREWAR_OBJ) $(COREWAR_HEADERS) -L. $(COREWAR_LIBFT_PATH) -o $(COREWAR) -lncurses
	@echo "Corewar binary -> done"

clean:
	@make clean -C $(ASM_SRC)
	@make clean -C $(COREWAR_SRC)

fclean: clean
	@make fclean -C $(ASM_SRC)
	@make fclean -C $(COREWAR_SRC)
	@/bin/rm -f $(ASM)
	@/bin/rm -f $(COREWAR)

re: fclean all