# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchapard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:50:00 by lchapard          #+#    #+#              #
#    Updated: 2023/11/27 16:52:19 by lchapard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./src/push_swap.c ./src/push_swap_utils.c ./src/split_argv.c \
./src/cost.c ./src/findings.c ./src/parsing.c ./src/prepare_push.c \
./src/pushing.c ./src/reverse_rotating.c ./src/rotating.c \
./src/savings.c ./src/swap.c
HEADERS = ./include/push_swap.h
DPRINTF = ./ft_printf
PRTF = $(DPRINTF)/printf.a

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(PRTF)
	$(CC) $^ $(CFLAGS) $(DPRINTF)/printf.a -o $(NAME)

$(PRTF) : FORCE
	@$(MAKE) --no-print-directory -C $(DPRINTF)

%.o:%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	cd $(DPRINTF) && make clean
	rm -rf $(OBJS)

fclean : clean
	cd $(DPRINTF) && make fclean
	rm -rf $(NAME)

re : fclean all

FORCE :

.PHONY : all clean fclean re FORCE