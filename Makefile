# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2022/01/27 14:16:37 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME 	= ft_containers
NAMESTD = std_containers

INC_DIR	=	includes includes/map includes/stack includes/vector includes/iterator
INCLUDE	=	ft_stl.hpp \
			printer.tpp \
			type_traits.hpp \
			vector.hpp \
			vector_iterator.hpp \
			reverse_iterator.hpp \
			iterator_traits.hpp \
			map.hpp	\
			stack.hpp
			
HEADERS =	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.hpp) )

SRC_DIR	=	srcs srcs/vector
SRC		= 	main.cpp \
			test_iterator.cpp \
			test_empty.cpp \
			test_vector.cpp \
			test_insert.cpp \
			test_erase.cpp
			
OBJ_DIR =	obj/
OBJ_DIRSTD =	objstd/

OBJ 	=	$(addprefix $(OBJ_DIR),$(SRC:%.cpp=%.o))
OBJ_STD =	$(addprefix $(OBJ_DIRSTD),$(SRC:%.cpp=%.o))

# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC 		=	clang++

CFLAG 	= 	-Wall -Wextra -std=c++98 -pedantic -g
STDFLAG = -D M_NAMESPACE=std
IFLAG 	=	$(foreach dir, $(INC_DIR), -I $(dir)/ )


vpath %.cpp $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.hpp $(foreach dir, $(INC_DIR)/, $(dir):)

# ----------------- #
#	  FONCTIONS		#
# ----------------- #

all:		$(NAME) $(NAMESTD)

$(OBJ_DIR)%.o: %.cpp $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation of ... $(foreach file, $< , $(notdir $<))\033[0m"
			@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $< 

$(OBJ_DIRSTD)%.o: %.cpp $(HEADERS)
			@mkdir -p $(OBJ_DIRSTD)
			@echo "\033[32mCompilation of ... $(foreach file, $< , $(notdir $<))\033[0m"
			@$(CC) $(CFLAG) $(STDFLAG) $(IFLAG) -o $@ -c $< 

$(NAME):	$(OBJ)
			@$(CC) $(CFLAG) $(IFLAG) $(OBJ) -o $@ 
			@echo "\033[32mC\n*     Compilation $(NAME)     *\t   \033[32;1m--> Complete\033[0m"

$(NAMESTD):	$(OBJ_STD)
			@$(CC) $(CFLAG) $(STDFLAG) $(IFLAG) $(OBJ_STD) -o $@ 
			@echo "\033[32mC\n*     Compilation $(NAMESTD)     *\t   \033[32;1m--> Complete\033[0m"


# ----------------- #
# 		CLEAN		#
# ----------------- #

clean:
			rm -rf $(OBJ_DIR) $(OBJ_DIRSTD)

fclean: clean
			rm -f $(NAME) $(NAMESTD)

re: 	fclean all

.PHONY: all clean flcean re
