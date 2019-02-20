# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgorold- <dgorold-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 13:27:19 by dgorold-          #+#    #+#              #
#    Updated: 2019/02/15 12:14:00 by dgorold-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FILES = main.c input_output.c reading_file.c validation.c
OBJ = main.o input_output.o reading_file.o validation.o

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g -c -Wall -Wextra -Werror $(FILES) -I header.h
	gcc $(OBJ) -o $(NAME)

%.o: %.c header.h
	gcc -g -Wall -Wextra -Werror -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
