# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 23:12:19 by namorgha          #+#    #+#              #
#    Updated: 2023/04/07 05:35:00 by namorgha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc

OBJ = philo_bonus.c

OBJO = philo_bonus.o

all: $(NAME)

$(NAME): $(OBJO) philo_bonus.h
		$(CC) -Wall -Wextra -Werror $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJO)

fclean: clean
	rm -rf philo_bonus

re: fclean all
