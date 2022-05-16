# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 19:14:53 by lbarbosa          #+#    #+#              #
#    Updated: 2022/05/12 19:38:35 by lbarbosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

NAME2 = client

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -o

C_SRC1 = server.c

C_SRC2 = client.c

all: $(NAME) $(NAME2)

$(NAME): $(C_SRC1)
	@cd ft_printf && make && cd ..
	@$(CC) $(CFLAGS) $(NAME) minitalk.h $(C_SRC1) ft_printf/libftprintf.a

$(NAME2): $(C_SRC2)
	@cd ft_printf && make && cd ..
	@$(CC) $(CFLAGS) $(NAME) minitalk.h $(C_SRC1) ft_printf/libftprintf.a

clean:
	@cd ft_printf && make clean && cd ..

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME2)
	@cd ft_printf && make fclean && cd ..

re: fclean all

.PHONY: all clean fclean re