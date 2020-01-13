# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swarner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 15:34:46 by swarner           #+#    #+#              #
#    Updated: 2019/11/01 13:01:45 by swarner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = 	src/ft_strlen.c \
		src/ft_putchar.c \
		src/ft_putstr.c \
		src/ft_strdup.c \
		src/ft_atoi.c \
		src/ft_strcpy.c \
		src/ft_strncpy.c \
		src/ft_strcmp.c \
		src/ft_strncmp.c \
		src/ft_isdigit.c \
		src/ft_isprint.c \
		src/ft_isascii.c \
		src/ft_isalnum.c \
		src/ft_isalpha.c \
		src/ft_toupper.c \
		src/ft_tolower.c \
		src/ft_memset.c \
		src/ft_bzero.c \
		src/ft_memcpy.c \
		src/ft_memccpy.c \
		src/ft_memmove.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_strcat.c \
		src/ft_strncat.c \
		src/ft_strlcat.c \
		src/ft_strchr.c \
		src/ft_strrchr.c \
		src/ft_strstr.c \
		src/ft_strnstr.c \
		src/ft_putendl.c \
		src/ft_putnbr.c \
		src/ft_putchar_fd.c \
		src/ft_putstr_fd.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr_fd.c \
		src/ft_memalloc.c \
		src/ft_memdel.c \
		src/ft_strnew.c \
		src/ft_strdel.c \
		src/ft_strclr.c \
		src/ft_striter.c \
		src/ft_striteri.c \
		src/ft_strmap.c \
		src/ft_strmapi.c \
		src/ft_strequ.c \
		src/ft_strnequ.c \
		src/ft_strsub.c \
		src/ft_strjoin.c \
		src/ft_strtrim.c \
		src/ft_itoa.c \
		src/ft_strsplit.c \
		src/ft_lstnew.c \
		src/ft_lstadd.c \
		src/ft_lstdelone.c \
		src/ft_lstdel.c \
		src/ft_lstiter.c \
		src/ft_lstmap.c \
		src/ft_rejoin.c \
		src/ft_strjoin_free.c \
		src/get_next_line.c \
		src/ft_lsthead_del.c \
		src/ft_lstadd_end.c \
		src/ft_addnode.c \
		src/ft_addnode_dlist.c \
		src/ft_dlisthead_del.c \
		src/ft_dlistadd_end.c \
		src/ft_dlist_new.c \
		src/ft_free_dlist.c \
		src/ft_free_list.c \
		src/ft_abs.c \
		src/ft_itoa_base.c \
		src/ft_strlower.c \
		src/ft_strupper.c \
		src/ft_strjoin_free2.c \
		src/ft_strjoin_free_all.c \
		src/ft_search_helper.c \
		src/ft_strset.c

FLAGS = -Wall -Wextra -Werror -c
HEADERS = ./includes
OBJ = *.o

all: $(NAME)

$(NAME):	
	@gcc $(FLAGS) -I $(HEADERS) $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
