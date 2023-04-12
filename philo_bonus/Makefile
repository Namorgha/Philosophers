# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 23:09:41 by namorgha          #+#    #+#              #
#    Updated: 2023/04/12 01:25:18 by namorgha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc

FLAGS = -Wall -Werror -Wextra -fsanitize=address -g

OBJ = main_bonus.c creat_thread_bonus.c my_usleep_bonus.c timing_bonus.c info_bonus.c error_bonus.c death_bonus.c utils_bonus.c forks_bonus.c eating_bonus.c init_semaphore.c actions.c free.c

OBJO = main_bonus.o creat_thread_bonus.o my_usleep_bonus.o timing_bonus.o info_bonus.o error_bonus.o death_bonus.o utils_bonus.o forks_bonus.o eating_bonus.o init_semaphore.o actions.o free.o

all: $(NAME)

$(NAME): $(OBJO) philo_bonus.h
		$(CC) -Wall -Werror -Wextra $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJO)

fclean: clean
	rm -rf philo_bonus

re: fclean all
