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

all: $(ASM) $(COREWAR)

$(ASM):
	@make -C $(ASM_SRC)
	@mv $(ASM_SRC)/$(ASM) $(ASM)

$(COREWAR):
	@make -C $(COREWAR_SRC)
	@mv $(COREWAR_SRC)/$(COREWAR) $(COREWAR)

clean:
	@make clean -C $(ASM_SRC)
	@make clean -C $(COREWAR_SRC)

fclean: clean
	@make fclean -C $(ASM_SRC)
	@make fclean -C $(COREWAR_SRC)
	@/bin/rm -f $(ASM)
	@/bin/rm -f $(COREWAR)

re: fclean all