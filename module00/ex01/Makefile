# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 03:20:27 by pruenrua          #+#    #+#              #
#    Updated: 2024/04/16 09:30:23 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = phonebook

CC = c++

# -pedantic is force the compiler to be more strict about the std that include in the flag
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

CPP_FILE = MyUtil.cpp Contact.cpp Phonebook.cpp main.cpp

HPP_FILE = MyUtil.hpp Contact.hpp Phonebook.hpp

all : $(NAME)
	
$(NAME) : $(CPP_FILE) $(HPP_FILE)
	$(CC) $(CFLAGS) $(CPP_FILE) -o $(NAME)

clean :
	rm -f $(NAME)

re : clean all

.PHONY : all clean re 