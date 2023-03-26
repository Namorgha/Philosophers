# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 23:09:41 by namorgha          #+#    #+#              #
#    Updated: 2023/03/26 01:20:25 by namorgha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

OBJ = main.c test1.c test2.c

OBJO = main.o test1.o test2.o

all: $(NAME)

$(NAME):
		$(CC) -Wall -Wextra -Werror -pthread $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJO)

fclean: clean
	rm -f philo

re: fclean all
