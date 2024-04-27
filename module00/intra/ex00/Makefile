# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 17:24:08 by pruenrua          #+#    #+#              #
#    Updated: 2024/04/17 21:25:54 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = c++

# -pedantic is force the compiler to be more strict about the std that include in the flag
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC_FILE = megaphone.cpp

all : $(NAME)

OBJ = $(SRC_FILE:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : clean all

.PHONY : all clean re 