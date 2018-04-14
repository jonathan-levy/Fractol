# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolevy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 09:32:13 by jolevy            #+#    #+#              #
#    Updated: 2018/04/13 09:32:29 by jolevy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_memcpy.c ft_strequ.c ft_strcmp.c ft_str_to_lowcase.c ft_isupper.c \
		ft_itoa.c ft_puterror.c ft_putstr.c ft_putendl.c ft_strjoin.c \
		ft_strlen.c ft_strnew.c ft_strcpy.c ft_strcat.c ft_program_name.c \
		ft_strdup.c ft_strcap.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[INFO] Library [$(NAME)] created!"

clean:
	@rm -f $(OBJ)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] Library [$(NAME)] removed!"

re:	fclean all

.PHONY: all, clean, fclean, re
