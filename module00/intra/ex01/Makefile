# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 03:20:27 by pruenrua          #+#    #+#              #
#    Updated: 2024/04/17 22:26:22 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = phonebook

CXX = c++

# -pedantic is force the compiler to be more strict about the std that include in the flag
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

CPP_FILE = MyUtil.cpp Contact.cpp PhoneBook.cpp main.cpp

HPP_FILE = MyUtil.hpp Contact.hpp PhoneBook.hpp

all : $(NAME)

OBJ = $(CPP_FILE:.cpp=.o)

%.o: %.cpp $(HPP_FILE)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)

re : clean all

.PHONY : all clean re 