# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 17:24:08 by pruenrua          #+#    #+#              #
#    Updated: 2024/04/15 01:39:20 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++

# -pedantic is force the compiler to be more strict about the std that include in the flag
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC_FILE = megaphone.cpp

all : $(NAME)
	
$(NAME) : $(SRC_FILE)
	$(CC) $(CFLAGS) $(SRC_FILE) -o $(NAME)

clean :
	rm -f $(NAME)

re : clean all

.PHONY : all clean re 