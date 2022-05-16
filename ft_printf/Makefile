# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 20:45:57 by lbarbosa          #+#    #+#              #
#    Updated: 2022/03/02 19:24:53 by lbarbosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR =	../libft

HEADER = ft_printf.h -L../libft -lft

C_SRC = ft_printf.c ft_printf_c.c ft_printf_s.c ft_printf_di.c ft_printf_u.c ft_printf_p.c ft_printf_x.c ft_printf_mx.c

SRC_OBJ = $(C_SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	@make -C $(LIBFT_DIR)
	@cp ../libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(SRC_OBJ)
	@ranlib $(NAME)

.o.c:
	@$(CC) $(C_FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f *.o
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
