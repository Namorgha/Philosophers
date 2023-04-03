# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 23:09:41 by namorgha          #+#    #+#              #
#    Updated: 2023/04/03 12:53:52 by namorgha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

OBJ = main.c creat_thread.c mutex.c my_usleep.c timing.c info.c error.c death.c

OBJO = main.o creat_thread.o mutex.o my_usleep.o timing.o info.o error.o death.o

all: $(NAME)

$(NAME): $(OBJO) philo.h
		$(CC) -Wall -Wextra -Werror -pthread $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJO)

fclean: clean
	rm -f philo

re: fclean all
