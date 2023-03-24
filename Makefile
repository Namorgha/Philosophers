# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 23:09:41 by namorgha          #+#    #+#              #
#    Updated: 2023/03/23 20:58:13 by namorgha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

OBJ = main.c test1.c

OBJO = main.o test1.o

all: $(NAME)

$(NAME): $(OBJO)
		$(CC) -Wall -Wextra -Werror -pthread $^ -o $(NAME)

clean:
	rm -f $(OBJO)

fclean: clean
	rm -f philo

re: fclean all
