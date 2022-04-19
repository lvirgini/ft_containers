# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2022/04/18 22:32:57 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME 	= ft_containers
NAMESTD = std_containers


# Includes
# ----------------- #
INC_DIR	=	includes \
			includes/map \
			includes/stack \
			includes/vector \
			includes/others \
			includes/iterator \
			includes/red_black_tree 

INCLUDE	=	$(INC_MAP) $(INC_VECTOR) $(INC_STACK) $(INC_UTILS)\
				ft_stl.hpp \
				printer.tpp \

INC_STACK	=	stack.hpp \

INC_VECTOR	=	vector.hpp \

INC_MAP 	=	map.hpp	\

INC_UTILS 	=	usefull.hpp \
				type_traits.hpp \
				iterator_traits.hpp \
				normal_iterator.hpp \
				reverse_iterator.hpp \
				RedBlacktree.hpp \
				TreeNode.hpp \
				pair.hpp \
				
			
HEADERS 	=	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.hpp) )


# Sources
# ----------------- #

SRC_DIR		=	srcs srcs/vector srcs/stack srcs/map

SRC			= 	$(SRC_VECTOR) $(SRC_STACK) $(SRC_MAP) main.cpp \

SRC_VECTOR	=	vector_test_iterator.cpp \
				vector_test_empty.cpp \
				vector_test_vector.cpp \
				vector_test_insert.cpp \
				vector_test_push_pop.cpp \
				vector_test_operator.cpp \
				vector_test_assign.cpp \
				vector_test_erase.cpp \

SRC_STACK	=	stack_test.cpp \

SRC_MAP 	=	test_pair.cpp \
				test_rbtree.cpp \
				map_test_constructor.cpp \
				map_test_capacity.cpp \
				map_test_insert.cpp \
				map_test_erase.cpp

# Obj
# ----------------- #	
OBJ_DIR		=	obj/
OBJ_DIRSTD	=	objstd/

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
