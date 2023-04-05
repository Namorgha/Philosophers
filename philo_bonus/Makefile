# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 23:12:19 by namorgha          #+#    #+#              #
#    Updated: 2023/04/03 23:15:43 by namorgha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc

OBJ =

OBJO =

all: $(NAME)

$(NAME): $(OBJO) philo_bonus.h
		$(CC) -Wall -Wextra -Werror $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJO)

fclean: clean
	rm -rf philo_bonus

re: fclean all
