# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 21:51:07 by pruenrua          #+#    #+#              #
#    Updated: 2024/05/03 18:40:29 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = reference

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

CPP_FILE = main.cpp

HPP_FILE =

OBJ = $(CPP_FILE:.cpp=.o)

%.o: %.cpp $(HPP_FILE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(CPP_FILE) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re 